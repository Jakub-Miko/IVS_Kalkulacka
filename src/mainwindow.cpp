/** @file mainwindow.cpp
 * @brief Representation of the main window of the application.
 *
 * This class represents the main window of the application. It contains
 * functionalities for using the math_engine and interacting with the
 * user interface.
 *
 * @author Patrik Contofalsky, Jakub Miko
*/
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QKeyEvent>
#include <QMediaDevices>
#include <QAudioDevice>
#include <QMessageBox>
#include "mathlibrary.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), mode_choice(true), player(nullptr), output(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("E-Calculator");
    setWindowIcon(QIcon(":/resources/logo"));
    if(!QMediaDevices::defaultAudioOutput().isNull()) {
        output = new QAudioOutput(this);
	    player = new QMediaPlayer(this);
        player->setSource(QUrl("qrc:/resources/easter_egg.mp3"));
        player->setAudioOutput(output);
    }
    
    connect(ui->pushButton_number_0, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_1, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_2, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_3, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_4, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_5, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_6, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_7, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_8, SIGNAL(clicked()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_9, SIGNAL(clicked()), this, SLOT(number_clicked()));

}

MainWindow::~MainWindow()
{
    if(output) delete output;
    if(player) delete player;
    delete ui;
}

void MainWindow::PlaySound()
{
    if(!output) return;
    player->stop();
    player->setPosition(0);
    output->setVolume(50);
    player->play();
}

void MainWindow::number_clicked()
{
    QPushButton * Button = (QPushButton*)sender();

    QString LabelNumber;

    LabelNumber = (ui->display->text() + Button->text());
    ui->display->setText(LabelNumber);

}

/**
 * @brief Add a number to the display.
 *
 * Adds the clicked number to the display widget.
 *
 * @param ui Pointer to the main window's user interface.
 * @param NextNumber QString number to add to the display.
*/
void AddNumber(Ui::MainWindow* ui, QString NextNumber) {
    QString LabelNumber = (ui->display->text() + NextNumber);
    ui->display->setText(LabelNumber);
}

/**
 * @brief Replaces a part of string with another string.
 *
 * @param Text QString of the original string.
 * @param Find QString of the substring to find.
 * @param Replace QString of the substring to replace with.
 * @return QString The modified string.
*/
QString ReplaceString(QString Text, QString Find, QString Replace) {
    Text.replace(Find, Replace);
    return Text;
}

/**
 * @brief Sends the current number on the display to the math engine.
 *
 * Sends the current number on the display to the math engine for further processing.
 *
 * @param ui Pointer to the main window's user interface.
 * @param math Reference to the math engine instance.
*/
void SendNumberToEngine(Ui::MainWindow* ui, MathEngine& math) {
    if (!ui->display->text().isEmpty()) {
        long double ld = std::strtold(ReplaceString(ui->display->text(), ",", ".").toLatin1().data(),nullptr);
        const char* msg = nullptr;
        if((msg = math.SendNumber(ld).msg)) {
            QMessageBox::information(nullptr, "Warning", msg);
        }
    }
}

/**
 * @brief Shows the result of the calculation in the equation display.
 *
 * Returns the result of the calculation from the math engine
 * and displays it in the equation display.
 *
 * @param ui Pointer to the main window's user interface.
 * @param math Reference to the math engine instance.
*/
void ShowResult(Ui::MainWindow* ui, MathEngine& math) {
    ui->display->setText("");

    ui->equation->setText(math.GetDisplay().c_str());

}

void MainWindow::on_pushButton_backspace_clicked()
{
    QString LabelNumber;
    LabelNumber = (ui->display->text());
    LabelNumber.chop(1);
    ui->display->setText(LabelNumber);
}

void MainWindow::on_pushButton_clearfull_clicked()
{
    ui->display->setText("");
    ui->equation->setText("0");
    math.ResetAllContexts();
}


void MainWindow::on_pushButton_cleardisp_clicked()
{
    ui->display->setText("");
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{   //SWITCH CASE FOR NUMBERS
    switch(event->key()) {
    case Qt::Key_0:
        AddNumber(ui, "0");
        break;
    case Qt::Key_1:
        AddNumber(ui, "1");
        break;
    case Qt::Key_2:
        AddNumber(ui, "2");
        break;
    case Qt::Key_3:
        AddNumber(ui, "3");
        break;
    case Qt::Key_4:
        AddNumber(ui, "4");
        break;
    case Qt::Key_5:
        AddNumber(ui, "5");
        break;
    case Qt::Key_6:
        AddNumber(ui, "6");
        break;
    case Qt::Key_7:
        AddNumber(ui, "7");
        break;
    case Qt::Key_8:
        AddNumber(ui, "8");
        break;
    case Qt::Key_9:
        AddNumber(ui, "9");
        break;
    case Qt::Key_ParenLeft:
        on_pushButton_open_clicked();
        break;
    case Qt::Key_ParenRight:
        on_pushButton_close_clicked();
        break;
    case Qt::Key_Comma:
    case Qt::Key_Period:
        on_pushButton_comma_clicked();
        break;
    case Qt::Key_Backspace:
    {
        QString DisplayedWithoutLast = ui->display->text();
        DisplayedWithoutLast.chop(1);
        ui->display->setText(DisplayedWithoutLast);
        break;
    }
    case Qt::Key_Delete:
        ui->display->setText("");
        break;
    case Qt::Key_R:
        on_pushButton_clearfull_clicked();
        break;
    }

    // SWITCH CASES FOR OPERATIONS
    switch(event->key()) {
    case Qt::Key_Plus:
        on_pushButton_plus_clicked();
        break;
    case Qt::Key_Minus:
        on_pushButton_minus_clicked();
        break;
    case Qt::Key_Asterisk:
        on_pushButton_mul_clicked();
        break;
    case Qt::Key_Slash:
        on_pushButton_div_clicked();
        break;
    case Qt::Key_Exclam:
        on_pushButton_factorial_clicked();
        break;
    case Qt::Key_AsciiCircum:
        on_pushButton_power_clicked();
        break;
    case Qt::Key_L:
        on_pushButton_log_clicked();
        break;
    case Qt::Key_A:
        on_pushButton_abs_clicked();
        break;
    case Qt::Key_Equal:
    case Qt::Key_Enter:
    case Qt::Key_Return:
        on_pushButton_equals_clicked();
        break;
    }
}


void MainWindow::on_actionAbout_triggered()
{
    about_window = new about(this);
    about_window->show();
}

void MainWindow::on_pushButton_mode_clicked()
{
    ui->MOD_container->setCurrentIndex(mode_choice);
    if(mode_choice) mode_choice = false;
    else mode_choice = true;
}


void MainWindow::on_pushButton_plus_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendAdd();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_minus_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendSubtract();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_mul_clicked()
{
    try {
        if(math.GetContextStack().back().last_op == MathEngine::Operation::DEFAULT) {
            math.SendNumber(1);
        }
        SendNumberToEngine(ui, math);
        math.SendMultiply();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_div_clicked()
{
    try {
        if(math.GetContextStack().back().last_op == MathEngine::Operation::DEFAULT) {
            math.SendNumber(1);
        }
        SendNumberToEngine(ui, math);
        math.SendDivide();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_equals_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendEquals();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
            setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_comma_clicked()
{
    QString displayed = ui->display->text();
    if (displayed == ""){
        displayed = "0";
    }
    if (!displayed.contains(",")) {
        displayed = displayed + ",";
        ui->display->setText(displayed);
    }
}



void MainWindow::on_pushButton_root_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendRoot();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_power_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendPower();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }

}

// UNARY OPERATIONS
void MainWindow::on_pushButton_abs_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendAbsVal();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_factorial_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        const char* msg = nullptr;
        if((msg = math.SendFactorial().msg)) {
            QMessageBox::information(nullptr, "Warning", msg);
        }
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_log_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.Sendln();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}



void MainWindow::on_pushButton_pi_clicked()
{
    ui->display->setText(ReplaceString(QString::number((double)constants::const_pi, 'F', PRECISION_OF_NUMBER*2), ".", ","));
}


void MainWindow::on_pushButton_c_clicked()
{
    ui->display->setText(QString::number((double)constants::const_light, 'F', 0));
}


void MainWindow::on_pushButton_e_clicked()
{
    if(ui->actionSounds->isChecked()) {
        PlaySound();
    }
    ui->display->setText(ReplaceString(QString::number((double)constants::const_e, 'F', PRECISION_OF_NUMBER*2),".", ","));
}


void MainWindow::on_pushButton_chngval_clicked()
{
    QString Displayed = ui->display->text();
    if (!Displayed.isEmpty()) {
        if (Displayed[0] == '-') {
            Displayed.remove(0,1);
        } else
            Displayed = "-" + Displayed;
        ui->display->setText(Displayed);
    }

}

void MainWindow::on_pushButton_sine_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendSine();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_cosine_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendCosine();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_tangent_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.SendTangent();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}


void MainWindow::on_pushButton_open_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        math.StartContext();
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }

}


void MainWindow::on_pushButton_close_clicked()
{
    try {
        SendNumberToEngine(ui, math);
        const char* msg = nullptr;
        if((msg = math.EndContext().msg)) {
            QMessageBox::information(nullptr, "Warning", msg);
        }
        ShowResult(ui, math);
    } catch(const std::runtime_error& err) {
        QMessageBox::information(this, "Warning", err.what());
        setWindowModality(Qt::ApplicationModal);
    }
}

