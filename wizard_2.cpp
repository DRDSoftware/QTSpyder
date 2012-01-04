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

Wizard2::Wizard2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard2)
{
    ui->setupUi(this);

    quit = NULL;
}

Wizard2::~Wizard2()
{
    if(quit!=NULL)
    {
        delete quit;
    }
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
    if(quit==NULL)
    {
        quit = new QMessageBox();
        quit->setText(tr("The Wizard didn't finish yet."));
        quit->setInformativeText(tr("Do you want to quit the Wizard?"));
        quit->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        quit->setDefaultButton(QMessageBox::No);
        quit->setButtonText(QMessageBox::Yes , tr("Yes"));
        quit->setButtonText(QMessageBox::No , tr("No"));
    }
    int ret = quit->exec();
    switch(ret)
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

void Wizard2::Find()
{
    /// \todo Find all the cameras connected to the computer
    cam_enum.start();
}

void Wizard2::Connect()
{
    /// \todo Connection to the camera
    this->accept();
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

    Find();

    ui->wizard2Cancel->setEnabled(false);
}

void Wizard2::on_wizard2List_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->wizard2Connect->setEnabled(true);
}
