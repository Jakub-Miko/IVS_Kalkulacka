#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "qaudiooutput.h"
#include "qmediaplayer.h"
#include "math_engine.h"
#include "mathlibrary.h"

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

    void PlaySound();

private slots:
    void number_clicked();

    void keyReleaseEvent(QKeyEvent *);

    void on_pushButton_backspace_released();

    void on_pushButton_clearfull_released();

    void on_pushButton_cleardisp_released();

    void on_actionAbout_triggered();

    void on_pushButton_mode_released();

    void on_pushButton_plus_released();

    void on_pushButton_minus_released();

    void on_pushButton_mul_released();

    void on_pushButton_div_released();

    void on_pushButton_equals_released();

    void on_pushButton_comma_released();

    void on_pushButton_root_released();

    void on_pushButton_power_released();

    void on_pushButton_abs_released();

    void on_pushButton_pi_released();

    void on_pushButton_c_released();

    void on_pushButton_e_released();

    void on_pushButton_k_released();

    void on_pushButton_h_released();

private:
    QMediaPlayer* player;
    QAudioOutput* output;
    Ui::MainWindow *ui;
    about *about_window;
    bool mode_choice;
    MathEngine math;
};
#endif // MAINWINDOW_H
