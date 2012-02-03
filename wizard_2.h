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

#ifndef WIZARD_2_H
#define WIZARD_2_H

#include <QDialog>
#include <QMessageBox>
#include <QModelIndex>
#include <QListWidgetItem>
#include "cameraenumerator.h"

class MainWindow;

namespace Ui {
    class Wizard2;
}

class Wizard2 : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard2(QWidget *parent = 0);
    ~Wizard2();

    // Show the second pass of the Wizard
    void Show();

    // Hide the second pass of the Wizard
    void UnShow();

    // Exit the Wizard
    void Exit();

    // Connect to the selected camera
    void Connect();

private slots:
    void on_wizard2Exit_clicked();

    void on_wizard2Connect_clicked();

    // Find all the cameras connected
    void on_wizard2Find_clicked();

    void on_wizard2Cancel_clicked();

    void on_wizard2List_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_Find_finished();

private:
    Ui::Wizard2 *ui;
    CameraEnumerator cam_enum;
    MainWindow *parentWindow;
};

#endif // WIZARD_2_H
