#ifndef QTSPYDERWIZARD_H
#define QTSPYDERWIZARD_H

#include <QDialog>

namespace Ui {
    class Wizard1;
}

class Wizard1 : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard1(QWidget *parent = 0);
    ~Wizard1();

    // Mostra il Wizard di connessione alla telecamera
    void Show();

    // Nasconde il Wizard di connessione alla telecamera
    void UnShow();

private slots:
    void on_wizardFind_clicked();

    void on_wizardList_itemSelectionChanged();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Wizard1 *ui;
};

#endif // QTSPYDERWIZARD_H
