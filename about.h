#ifndef QTSPYDERABOUT_H
#define QTSPYDERABOUT_H

#include <QDialog>

namespace Ui {
    class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

    // Mostra la finestra
    void Show();

    // Nasconde la finestra
    void UnShow();

private:
    Ui::About *ui;
};

#endif // QTSPYDERABOUT_H
