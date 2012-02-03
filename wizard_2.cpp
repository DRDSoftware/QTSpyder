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

#include "wizard_2.h"
#include "ui_wizard_2.h"
#include "mainwindow.h"

Wizard2::Wizard2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard2)
{
    ui->setupUi(this);

    QObject::connect(&cam_enum, SIGNAL(finished()), this, SLOT(on_Find_finished()));

    parentWindow = static_cast<MainWindow*>(parent);
}

Wizard2::~Wizard2()
{
    delete ui;
}

void Wizard2::Show()
{
    this->setVisible(true);
}

void Wizard2::UnShow()
{
    this->setVisible(false);
}

void Wizard2::Exit()
{
    QMessageBox quit;
    quit.setText(tr("The Wizard didn't finish yet."));
    quit.setInformativeText(tr("Do you want to quit the Wizard?"));
    quit.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    quit.setDefaultButton(QMessageBox::No);
    quit.setButtonText(QMessageBox::Yes , tr("Yes"));
    quit.setButtonText(QMessageBox::No , tr("No"));

    switch(quit.exec())
    {
        case QMessageBox::Yes:
            if(cam_enum.isSearching())
            {
                cam_enum.stop();
            }
            UnShow();
            this->reject();
            break;

        case QMessageBox::No:
        default:
            break;
    }
}

void Wizard2::Connect()
{
    /// \todo Connection to the camera
    QMessageBox msg;
    QString cam_id = ui->wizard2List->currentItem()->text();

    ui->wizard2StatusMessage->setText(tr("Connecting to the selected camera..."));
    ui->wizard2StatusMessage->update();
    ui->wizard2StatusMessage->repaint();

    if(parentWindow->camera.Connect(&cam_id)==false)
    {
        msg.setIcon(QMessageBox::Critical);
        msg.setText(tr("An error has occurred when connecting to the camera ")+cam_id);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        ui->wizard2StatusMessage->setText(tr("Connection error"));
    }
    else
    {
        msg.setIcon(QMessageBox::Information);
        msg.setText(tr("Successfully connected to the camera ")+cam_id);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        this->accept();
    }
}

void Wizard2::on_wizard2Exit_clicked()
{
    Exit();
}

void Wizard2::on_wizard2Connect_clicked()
{
    Connect();
}

void Wizard2::on_wizard2Find_clicked()
{
    // Enable the user to stop the Find operation
    ui->wizard2Cancel->setEnabled(true);
    ui->wizard2Find->setEnabled(false);

    ui->wizard2StatusMessage->setText(tr("Searching for cameras..."));

    ui->wizard2List->clear();

    cam_enum.start();
}

void Wizard2::on_wizard2Cancel_clicked()
{
    cam_enum.stop();
}

void Wizard2::on_wizard2List_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    current;
    previous;
    ui->wizard2Connect->setEnabled(true);
}

void Wizard2::on_Find_finished()
{
    ui->wizard2Cancel->setEnabled(false);
    ui->wizard2Find->setEnabled(true);

    ui->wizard2StatusMessage->setText(tr("Search terminated."));

    char **results;
    // Get the number of cameras connected
    int count=cam_enum.getNumCameras();
    // Initialize the results vector
    results = new char*[count];
    // Get the IDs of all the camera connected
    for(int i=0; i<count; i++)
    {
        results[i] = new char[65];
        cam_enum.getCameraID(i, results[i]);
        QString temp = results[i];
        ui->wizard2List->addItem(new QListWidgetItem(temp));
    }
    // Delete the IDs from memory
    for(int i=0; i<count; i++)
    {
        delete results[i];
    }
    delete results;
}
