#include "wizard_1.h"
#include "ui_wizard_1.h"

Wizard1::Wizard1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard1)
{
    ui->setupUi(this);
}

Wizard1::~Wizard1()
{
    delete ui;
}

void Wizard1::Show()
{
    this->setVisible(true);
}

void Wizard1::UnShow()
{
    this->setVisible(false);
}

void Wizard1::on_wizardFind_clicked()
{
    /// \todo Collegamento alla cerca del core
}

void Wizard1::on_wizardList_itemSelectionChanged()
{
    /// \todo Salvataggio della telecamera selezionata
}

void Wizard1::on_buttonBox_accepted()
{
    /// \todo Controllare che ci sia una telecamera selezionata e fare la Connect
}

void Wizard1::on_buttonBox_rejected()
{
    /// \todo Chiudere la finestra e annullare la ricerca in corso
}
