#ifndef QTSPYDERMAINWINDOW_H
#define QTSPYDERMAINWINDOW_H

#include <QMainWindow>
#include <about.h>
#include <wizard.h>

namespace Ui {
    class QTSpyderMainWindow;
}

class QTSpyderMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QTSpyderMainWindow(QWidget *parent = 0);
    ~QTSpyderMainWindow();

private slots:
    void on_actionA_proposito_di_triggered();

protected:
    void ShowAbout();
    void ShowWizard();

private:

    Ui::QTSpyderMainWindow *ui;
    QTSpyderAbout *about;
    QTSpyderWizard *wizard;
};

#endif // QTSPYDERMAINWINDOW_H
