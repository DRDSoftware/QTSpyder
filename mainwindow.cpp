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
    about = NULL;
    /// \todo This should only be done if the user requested
    ///       the window to be shown at every boot
    ShowAbout();
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
    about->Show();
}

void MainWindow::ShowWizard1()
{
    if(wizard_1==NULL)
    {
        wizard_1 = new Wizard1(this);
    }
    wizard_1->Show();
}

void MainWindow::ShowWizard2()
{
    if(wizard_2==NULL)
    {
        wizard_2 = new Wizard2(this);
    }
    //wizard_2->Show();
}

void MainWindow::on_actionAbout_triggered()
{
    ShowAbout();
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

bool MainWindow::SaveAndExit()
{
    if(saveAndQuit==NULL)
    {
        saveAndQuit = new QMessageBox();
        saveAndQuit->setText(tr("The configuration has changed."));
        saveAndQuit->setInformativeText(tr("Do you want to save your changes?"));
        saveAndQuit->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        saveAndQuit->setDefaultButton(QMessageBox::Save);
    }
    int ret = saveAndQuit->exec();
    switch(ret)
    {
        case QMessageBox::Save:
            /// \todo Save the configuration
            return true;
            break;
        case QMessageBox::Discard:
            return true;
            break;
        case QMessageBox::Cancel:
        default:
            break;
    }
    return false;
}
