#include "wizard.h"
#include "ui_wizard.h"

QTSpyderWizard::QTSpyderWizard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTSpyderWizard)
{
    ui->setupUi(this);
}

QTSpyderWizard::~QTSpyderWizard()
{
    delete ui;
}

void QTSpyderWizard::Show()
{
    this->setVisible(true);
}

void QTSpyderWizard::UnShow()
{
    this->setVisible(false);
}

void QTSpyderWizard::on_wizardCerca_clicked()
{
    /// \todo Collegamento alla cerca del core
}

void QTSpyderWizard::on_wizardList_itemSelectionChanged()
{
    /// \todo Salvataggio della telecamera selezionata
}

void QTSpyderWizard::on_buttonBox_accepted()
{
    /// \todo Controllare che ci sia una telecamera selezionata e fare la Connect
}

void QTSpyderWizard::on_buttonBox_rejected()
{
    /// \todo Chiudere la finestra e annullare la ricerca in corso
}
