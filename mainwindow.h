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

#ifndef QTSPYDERMAINWINDOW_H
#define QTSPYDERMAINWINDOW_H

#include <QMainWindow>
#include <about.h>
#include <wizard_1.h>
#include <wizard_2.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

protected:
    void ShowAbout();
    void ShowWizard1();
    void ShowWizard2();

private:

    Ui::MainWindow *ui;
    About *about;
    Wizard1 *wizard_1;
    Wizard2 *wizard_2;
};

#endif // QTSPYDERMAINWINDOW_H
