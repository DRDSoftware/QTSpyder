/*
 * QTSpyder - An interface to use Dalsa Spyder3 1k, 36 kHz GigE camera
 * Copyright (C) 2011-2012 DRDSoftware
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"

#include <QStyle>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        ));
    this->setWindowState(Qt::WindowMaximized);
    this->show();

    about = NULL;
    if(Config::getMonoton()->getShowAbout())
    {
        ShowAbout();
    }
    wizard_1 = NULL;
    wizard_2 = NULL;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerRefreshed()));
    timer->start(30000);

    connect(&camera, SIGNAL(finishedAcquiring(bool)), this, SLOT(onFinishedAcquiring(bool)));

    ShowWizard();
}

MainWindow::~MainWindow()
{
    if(timer!=NULL)
    {
        if(timer->isActive())
        {
            timer->stop();
        }
        delete timer;
    }
    if(about!=NULL)
    {
        delete about;
    }
    if(wizard_1!=NULL)
    {
        delete wizard_1;
    }
    if(wizard_2!=NULL)
    {
        delete wizard_2;
    }
    delete ui;
}

void MainWindow::LockMe()
{
    this->setEnabled(false);
}

void MainWindow::UnLockMe()
{
    this->setEnabled(true);
}

void MainWindow::ShowAbout()
{
    if(about==NULL)
    {
        about = new About(this);
    }
    if(about->exec()==QDialog::Accepted)
    {
        Config::getMonoton()->setShowAbout(true);
    }
    else
    {
        Config::getMonoton()->setShowAbout(false);
    }
}

void MainWindow::ShowWizard()
{
    int ret1, ret2;

    if(wizard_1==NULL)
    {
        wizard_1 = new Wizard1(this);
    }

    ret1 = wizard_1->exec();

    if(ret1 != QDialog::Accepted)
    {
        return;
    }

    if(wizard_2==NULL)
    {
        wizard_2 = new Wizard2(this);
    }

    ret2 = wizard_2->exec();

    if(ret2 != QDialog::Accepted)
    {
        return;
    }

    // Successful connected at the camera

    ui->actionConnect->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);
    ui->actionAcquireImage->setEnabled(true);
    ui->actionContinuous_Capture->setEnabled(true);
    ui->singleCapture->setEnabled(true);
    ui->continuousCapture->setEnabled(true);
}

bool MainWindow::SaveAndExit()
{
    QString err;

    QMessageBox saveAndQuit;
    saveAndQuit.setIcon(QMessageBox::Question);
    saveAndQuit.setText(tr("The configuration has changed."));
    saveAndQuit.setInformativeText(tr("Do you want to save your changes?"));
    saveAndQuit.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    saveAndQuit.setDefaultButton(QMessageBox::Save);
    saveAndQuit.setButtonText(QMessageBox::Save, tr("Save"));
    saveAndQuit.setButtonText(QMessageBox::Discard, tr("Discard"));
    saveAndQuit.setButtonText(QMessageBox::Cancel, tr("Cancel"));

    int ret = saveAndQuit.exec();
    switch(ret)
    {
        case QMessageBox::Save:
            err=Config::getMonoton()->SaveToFile();
            if(err!="")
            {
                QMessageBox msg;
                msg.setIcon(QMessageBox::Critical);
                msg.setText(tr("An error has occurred when saving the configuration."));
                msg.setInformativeText(err);
                msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry);
                msg.setButtonText(QMessageBox::Ok, tr("Don't save the config"));
                msg.setButtonText(QMessageBox::Retry, tr("Retry"));

                while(msg.exec()==QMessageBox::Retry)
                {
                    err=Config::getMonoton()->SaveToFile();
                    if(err=="")
                    {
                        break;
                    }
                    msg.setInformativeText(err);
                }
            }
            return true;

        case QMessageBox::Discard:
            return true;

        case QMessageBox::Cancel:
        default:
            break;
    }

    return false;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(SaveAndExit()==true)
    {
        camera.Disconnect();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    ShowAbout();
}

void MainWindow::on_actionConnect_triggered()
{
    ShowWizard();
}

void MainWindow::on_actionRestoreDefaultConfig_triggered()
{
    Config::getMonoton()->LoadDefaultValues();
}

void MainWindow::onTimerRefreshed()
{
    if(camera.isConnected())
    {
        ui->temperature->setText(QString::number(camera.getTemperature()));
        ui->voltage->setText(QString::number(camera.getVoltage()));
    }
    else
    {
        ui->temperature->setText("");
        ui->voltage->setText("");
    }
}

void MainWindow::on_actionDisconnect_triggered()
{
    camera.Disconnect();

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionAcquireImage->setEnabled(false);
    ui->actionContinuous_Capture->setEnabled(false);
    ui->singleCapture->setEnabled(false);
    ui->continuousCapture->setEnabled(false);

    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    msg.setText(tr("Disconnected from the camera"));
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}

void MainWindow::on_actionAcquireImage_triggered()
{
    cap_image.create(&camera);

    qDebug()<<"Start acquiring....";
    camera.acquireImage(&cap_image);
}

void MainWindow::onFinishedAcquiring(bool result)
{
    qDebug()<<"Acquisizione finita";
    if(result)
    {
        QPixmap pixmap = QPixmap::fromImage(*cap_image.getImage(), Qt::ThresholdDither | Qt::NoOpaqueDetection);
        ui->label->setPixmap(pixmap);

        if(cap_image.save("test.png")==false)
        {
            qDebug()<<"Image not saved";
        }
    }

    cap_image.destroy();
}
