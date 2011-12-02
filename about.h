#ifndef QTSPYDERABOUT_H
#define QTSPYDERABOUT_H

#include <QDialog>

namespace Ui {
    class QTSpyderAbout;
}

class QTSpyderAbout : public QDialog
{
    Q_OBJECT

public:
    explicit QTSpyderAbout(QWidget *parent = 0);
    ~QTSpyderAbout();

    // Mostra la finestra
    void Show();

    // Nasconde la finestra
    void UnShow();

private:
    Ui::QTSpyderAbout *ui;
};

#endif // QTSPYDERABOUT_H
