#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void number_clicked();

    void keyReleaseEvent(QKeyEvent *);

    void on_pushButton_backspace_released();

    void on_pushButton_clearfull_released();

    void on_pushButton_cleardisp_released();

    void on_actionSettings_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    settings *settings_window;
    about *about_window;
};
#endif // MAINWINDOW_H
