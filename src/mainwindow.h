#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_backspace_released();

    void on_pushButton_clearfull_released();

    void on_pushButton_cleardisp_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
