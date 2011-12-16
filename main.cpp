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

#include <QtGui/QApplication>
#include <QTranslator>
#include <QDebug>
#include "mainwindow.h"
#include "config.h"

Config gbConfig;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //config.SaveToFile("QTSpyder.cfg");
    if(gbConfig.LoadFromFile("QTSpyder.cfg")!="")
    {
        gbConfig.LoadDefoultValues();
    }

    QString locale = QLocale::system().name();

    QTranslator translator;
    if(translator.load(QString("qtspyder_") + locale, ":/locales")==false)
    {
        qDebug()<<"Unable to load locale for "<<locale<<" trying with en_US...";
        if(translator.load("qtspyder_en_US", ":/locales")==false)
        {
            qDebug()<<"Unable to load locale en_US!!!";
        }
    }
    else
    {
        a.installTranslator(&translator);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
