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

#ifndef WIZARD_1_H
#define WIZARD_1_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class Wizard1;
}

class Wizard1 : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard1(QWidget *parent = 0);
    ~Wizard1();

    // Show the first pass of the Wizard
    void Show();

    // Hide the first pass of the Wizard
    void UnShow();

    // Exit the Wizard
    void Exit();

private slots:
    void on_wizard1Exit_clicked();

private:
    Ui::Wizard1 *ui;

    QMessageBox *quit;
};

#endif // WIZARD_1_H
