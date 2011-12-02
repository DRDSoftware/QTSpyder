#include "about.h"
#include "ui_about.h"

QTSpyderAbout::QTSpyderAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTSpyderAbout)
{
    ui->setupUi(this);
}

QTSpyderAbout::~QTSpyderAbout()
{
    delete ui;
}

void QTSpyderAbout::Show()
{
    this->setVisible(true);
}

void QTSpyderAbout::UnShow()
{
    this->setVisible(false);
}
