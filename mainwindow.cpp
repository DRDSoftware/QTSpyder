#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    about = NULL;
    wizard_1 = NULL;
    wizard_2 = NULL;
}

MainWindow::~MainWindow()
{
    if(about!=NULL)
    {
        delete about;
    }
    if(wizard_1!=NULL)
    {
        delete wizard_1;
    }
    if(wizard_2!=NULL)
    {
        delete wizard_2;
    }
    delete ui;
}

void MainWindow::ShowAbout()
{
    if(about==NULL)
    {
        about = new About(this);
    }
    about->Show();
}

void MainWindow::ShowWizard1()
{
    if(wizard_1==NULL)
    {
        wizard_1 = new Wizard1(this);
    }
    wizard_1->Show();
}

void MainWindow::ShowWizard2()
{
    if(wizard_2==NULL)
    {
        wizard_2 = new Wizard2(this);
    }
    //wizard_2->Show();
}

void MainWindow::on_actionAbout_triggered()
{
    ShowAbout();
}
