#ifndef QTSPYDERMAINWINDOW_H
#define QTSPYDERMAINWINDOW_H

#include <QMainWindow>
#include <about.h>
#include <wizard_1.h>
#include <wizard_2.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

protected:
    void ShowAbout();
    void ShowWizard1();
    void ShowWizard2();

private:

    Ui::MainWindow *ui;
    About *about;
    Wizard1 *wizard_1;
    Wizard2 *wizard_2;
};

#endif // QTSPYDERMAINWINDOW_H
