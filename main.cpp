#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTSpyderMainWindow w;
    w.show();

    return a.exec();
}
