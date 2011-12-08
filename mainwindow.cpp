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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    about = NULL;
    /// \todo This should only be done if the user requested
    ///       the window to be shown at every boot
    ShowAbout();
    wizard_1 = NULL;
    wizard_2 = NULL;
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
    delete ui;
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
