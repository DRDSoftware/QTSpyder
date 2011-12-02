#ifndef QTSPYDERWIZARD_H
#define QTSPYDERWIZARD_H

#include <QDialog>

namespace Ui {
    class QTSpyderWizard;
}

class QTSpyderWizard : public QDialog
{
    Q_OBJECT

public:
    explicit QTSpyderWizard(QWidget *parent = 0);
    ~QTSpyderWizard();

    // Mostra il Wizard di connessione alla telecamera
    void Show();

    // Nasconde il Wizard di connessione alla telecamera
    void UnShow();

private slots:
    void on_wizardCerca_clicked();

    void on_wizardList_itemSelectionChanged();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::QTSpyderWizard *ui;
};

#endif // QTSPYDERWIZARD_H
