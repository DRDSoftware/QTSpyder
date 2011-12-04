#include "wizard_2.h"
#include "ui_wizard_2.h"

Wizard2::Wizard2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard2)
{
    ui->setupUi(this);
}

Wizard2::~Wizard2()
{
    delete ui;
}
