#include "about.h"
#include "ui_about.h"

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

void About::Show()
{
    this->setVisible(true);
}

void About::UnShow()
{
    this->setVisible(false);
}
