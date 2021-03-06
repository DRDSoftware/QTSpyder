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

#include "about.h"
#include "ui_about.h"
#include "config.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_aboutOK_clicked()
{
    /// \todo Save the onBoot setting
    if(ui->aboutShowNextBoot->isChecked())
    {
        //UnShow();
        this->accept();
    }
    else
    {
        //UnShow();
        this->reject();
    }
}

void About::on_aboutShowNextBoot_stateChanged(int arg1)
{
    Config::getMonoton()->setShowAbout((arg1==Qt::Checked)?true:false);
}
