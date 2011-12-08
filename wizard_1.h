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

#ifndef QTSPYDERWIZARD_H
#define QTSPYDERWIZARD_H

#include <QDialog>

namespace Ui {
    class Wizard1;
}

class Wizard1 : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard1(QWidget *parent = 0);
    ~Wizard1();

    // Mostra il Wizard di connessione alla telecamera
    void Show();

    // Nasconde il Wizard di connessione alla telecamera
    void UnShow();

private slots:
    void on_wizardFind_clicked();

    void on_wizardList_itemSelectionChanged();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Wizard1 *ui;
};

#endif // QTSPYDERWIZARD_H
