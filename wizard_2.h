#ifndef WIZARD_2_H
#define WIZARD_2_H

#include <QDialog>

namespace Ui {
    class Wizard2;
}

class Wizard2 : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard2(QWidget *parent = 0);
    ~Wizard2();

private:
    Ui::Wizard2 *ui;
};

#endif // WIZARD_2_H
