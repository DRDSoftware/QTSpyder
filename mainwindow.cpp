#include "mainwindow.h"
#include "ui_mainwindow.h"

QTSpyderMainWindow::QTSpyderMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTSpyderMainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    about = NULL;
    wizard = NULL;
}

QTSpyderMainWindow::~QTSpyderMainWindow()
{
    if(about!=NULL)
    {
        delete about;
    }
    if(wizard!=NULL)
    {
        delete wizard;
    }
    delete ui;
}

void QTSpyderMainWindow::ShowAbout()
{
    if(about==NULL)
    {
        about = new QTSpyderAbout(this);
    }
    about->Show();
}

void QTSpyderMainWindow::ShowWizard()
{
    if(wizard==NULL)
    {
        wizard = new QTSpyderWizard(this);
    }
    wizard->Show();
}

void QTSpyderMainWindow::on_actionA_proposito_di_triggered()
{
    ShowAbout();
}
