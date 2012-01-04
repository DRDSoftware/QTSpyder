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

#include "wizard_1.h"
#include "ui_wizard_1.h"

Wizard1::Wizard1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard1)
{
    ui->setupUi(this);

    quit = NULL;
}

Wizard1::~Wizard1()
{
    if(quit!=NULL)
    {
        delete quit;
    }
    delete ui;
}

void Wizard1::Show()
{
    this->setVisible(true);
}

void Wizard1::UnShow()
{
    this->setVisible(false);
}

void Wizard1::Exit()
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
            UnShow();
            this->reject();
            break;
        case QMessageBox::No:
        default:
            break;
    }
}

void Wizard1::on_wizard1Exit_clicked()
{
    Exit();
}
