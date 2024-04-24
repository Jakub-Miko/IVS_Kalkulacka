/** @file mainwindow.h
 * @brief Representation of the main window of the application.
 *
 * This class represents the main window of the application. It contains
 * functionalities for using the math_engine and interacting with the
 * user interface.
 *
 * @author Patrik Contofalsky, Jakub Miko
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "qaudiooutput.h"
#include "qmediaplayer.h"
#include "math_engine.h"

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

    /**
     * @brief Play sound effect.
    */
    void PlaySound();

private slots:

    /**
     * @brief Print a number on the display when button is clicked.
    */
    void number_clicked();

    /**
     * @brief Slot called when a key is pressed.
     *
     * @param event Pointer to the key event.
    */
    void keyPressEvent(QKeyEvent *);

    /**
     * @brief Remove the last character from the display.
    */
    void on_pushButton_backspace_clicked();

    /**
     * @brief Reset the calculator (display, math engine).
    */
    void on_pushButton_clearfull_clicked();

    /**
     * @brief Clear main display.
    */
    void on_pushButton_cleardisp_clicked();

    /**
     * @brief Open new "About" window.
    */
    void on_actionAbout_triggered();

    /**
     * @brief Change mods of calculator.
     *
     * Changes between functions mode and constant mode.
    */
    void on_pushButton_mode_clicked();

    /**
     * @brief Addition operation.
     *
     * Binary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_plus_clicked();

    /**
     * @brief Substract operation.
     *
     * Binary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_minus_clicked();

    /**
     * @brief Multiplication operation.
     *
     * Binary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_mul_clicked();

    /**
     * @brief Division operation.
     *
     * Binary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_div_clicked();

    /**
     * @brief Equals operation.
     *
     * Performs the current arithmetic
     * operation based on the operands stored in the calculator's memory and displays the result.
    */
    void on_pushButton_equals_clicked();

    /**
     * @brief Print a comma on the display.
    */
    void on_pushButton_comma_clicked();

    /**
     * @brief Root operation.
     *
     * Binary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_root_clicked();

    /**
     * @brief Power operation.
     *
     * Binary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_power_clicked();


    /**
     * @brief Absolute value of number.
     *
     * Operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_abs_clicked();

    /**
     * @brief Print a Pi constant on the display.
    */
    void on_pushButton_pi_clicked();

    /**
     * @brief Print a c constant on the display.
    */
    void on_pushButton_c_clicked();

    /**
     * @brief Print a e constant on the display.
    */
    void on_pushButton_e_clicked();

    /**
     * @brief Calculate the factorial of the number.
     *
     * Unary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_factorial_clicked();

    /**
     * @brief Calculate the natural logarithm of the number.
     *
     * Unary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_log_clicked();

    /**
     * @brief Change the value of the number in the main display.
    */
    void on_pushButton_chngval_clicked();

    /**
     * @brief Calculate the sine of the number.
     *
     * Unary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_sine_clicked();

    /**
     * @brief Calculate the cosine of the number.
     *
     * Unary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_cosine_clicked();

    /**
     * @brief Calculate the tangent of the number.
     *
     * Unary operation based on the current state of the calculator and updates the display accordingly.
    */
    void on_pushButton_tangent_clicked();

    /**
     * @brief Print an open paranthesis on the display when it is possible.
    */
    void on_pushButton_open_clicked();

    /**
     * @brief Print a close paranthesis on the display when it is possible.
    */
    void on_pushButton_close_clicked();



private:
    QMediaPlayer* player; ///< Pointer to the sound player.
    QAudioOutput* output; ///< Pointer to the audio output.
    Ui::MainWindow *ui; ///< Pointer to the graphical interface.
    about *about_window; ///< Pointer to the "About" window.
    bool mode_choice; ///< Variable indicating the mode choice.
    MathEngine math; ///< Instance of the math engine.

};
#endif // MAINWINDOW_H
