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

    void keyPressEvent(QKeyEvent *);

    void on_pushButton_backspace_clicked();

    void on_pushButton_clearfull_clicked();

    void on_pushButton_cleardisp_clicked();

    void on_actionAbout_triggered();

    void on_pushButton_mode_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_equals_clicked();

    void on_pushButton_comma_clicked();

    void on_pushButton_root_clicked();

    void on_pushButton_power_clicked();

    void on_pushButton_abs_clicked();

    void on_pushButton_pi_clicked();

    void on_pushButton_c_clicked();

    void on_pushButton_e_clicked();

    void on_pushButton_k_clicked();

    void on_pushButton_h_clicked();

    void on_pushButton_factorial_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_chngval_clicked();

private:
    QMediaPlayer* player;
    QAudioOutput* output;
    Ui::MainWindow *ui;
    about *about_window;
    bool mode_choice;
    MathEngine math;
};
#endif // MAINWINDOW_H
