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
    quit = NULL;
    saveAndQuit = NULL;
}

MainWindow::~MainWindow()
{
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
    if(quit!=NULL)
    {
        delete quit;
    }
    if(saveAndQuit!=NULL)
    {
        delete saveAndQuit;
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

    /// \todo Connection with the camera selected (how to receive which one was chosen?)
    ///       Solution (?): make the connection in the Wizard and receive only the status here
}

bool MainWindow::SaveAndExit()
{
    QString err;

    if(saveAndQuit==NULL)
    {
        saveAndQuit = new QMessageBox();
        saveAndQuit->setIcon(QMessageBox::Question);
        saveAndQuit->setText(tr("The configuration has changed."));
        saveAndQuit->setInformativeText(tr("Do you want to save your changes?"));
        saveAndQuit->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        saveAndQuit->setDefaultButton(QMessageBox::Save);
        saveAndQuit->setButtonText(QMessageBox::Save, tr("Save"));
        saveAndQuit->setButtonText(QMessageBox::Discard, tr("Discard"));
        saveAndQuit->setButtonText(QMessageBox::Cancel, tr("Cancel"));
    }
    int ret = saveAndQuit->exec();
    switch(ret)
    {
        case QMessageBox::Save:
            err=Config::getMonoton()->SaveToFile();
            if(err!="")
            {
                QMessageBox *msg = new QMessageBox();
                msg->setIcon(QMessageBox::Critical);
                msg->setText(tr("An error has occurred when saving the configuration."));
                msg->setInformativeText(err);
                msg->setStandardButtons(QMessageBox::Ok | QMessageBox::Retry);
                msg->setButtonText(QMessageBox::Ok, tr("Don't save the config"));
                msg->setButtonText(QMessageBox::Retry, tr("Retry"));

                while(msg->exec()==QMessageBox::Retry)
                {
                    err=Config::getMonoton()->SaveToFile();
                    if(err=="")
                    {
                        break;
                    }
                    msg->setInformativeText(err);
                }

                delete msg;
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
