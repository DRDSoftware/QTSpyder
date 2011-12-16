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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtGui/QCloseEvent>
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
    /// Action to be executed when the
    /// About menu option is triggered
    void on_actionAbout_triggered();

    void on_actionConnect_triggered();

protected:
    /// Lock the UI of the window
    void LockMe();
    /// Unlock the UI of the window
    void UnLockMe();

    /// Show the About/Splash window
    /// and set in the configuration
    /// if the user want to see the
    /// about window on startup
    void ShowAbout();
    /// Show and handle the Wizard
    void ShowWizard();

    /// Override the default Close event
    void closeEvent(QCloseEvent *event);
    /// Save and Exit the program
    bool SaveAndExit();
private:
    /// The main window of the program
    Ui::MainWindow *ui;
    /// About/Splash window
    About *about;
    /// First pass of the Wizard
    Wizard1 *wizard_1;
    /// Second pass of the Wizard
    Wizard2 *wizard_2;

    /// A small MessageBox asking if the
    /// user want to exit the application
    QMessageBox *quit;
    /// A small MessageBox asking if the
    /// user want to exit the application
    /// or if he want to save before
    QMessageBox *saveAndQuit;
};

#endif // MAINWINDOW_H
