#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
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
    player->setSource(QUrl("qrc:/resources/easter_egg.mp3"));
    player->setAudioOutput(output);
    output->setVolume(50);
    player->play();
}

void MainWindow::number_clicked()
{
    QPushButton * Button = (QPushButton*)sender();

    QString LabelNumber;

    LabelNumber = (ui->display->text() + Button->text());
    ui->display->setText(LabelNumber);
    //ui->display->setAlignment(Qt::AlignRight);

}

void AddNumber(Ui::MainWindow* ui, QString NextNumber) {
    QString LabelNumber = (ui->display->text() + NextNumber);
    ui->display->setText(LabelNumber);
}

QString ReplaceString(QString Text, QString Find, QString Replace) {
    Text.replace(Find, Replace);
    return Text;
}

void SendNumberToEngine(Ui::MainWindow* ui, MathEngine& math) {
    if (!ui->display->text().isEmpty()) {
        long double ld = std::strtold(ReplaceString(ui->display->text(), ",", ".").toLatin1().data(),nullptr);
        const char* msg = nullptr;
        if((msg = math.SendNumber(ld).msg)) {
            QMessageBox::information(nullptr, "Warning", msg);
        }
    }
}

void ShowResult(Ui::MainWindow* ui, MathEngine& math) {
    // long double ld = math.GetAccumulator();
    // ld = std::round(Power(10, PRECISION_OF_NUMBER) * ld) / Power(10, PRECISION_OF_NUMBER);
    // std::stringstream ss;
    // ss << std::setprecision(PRECISION_OF_NUMBER) << ld;
    // std::string text = ss.str();
    // //ui->equation->setText(ReplaceString(QString::number((double)ld,'F', PRECISION_OF_NUMBER), ".", ","));
    // ui->equation->setText(ReplaceString(QString::fromStdString(text), ",", ","));
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
        qInfo("More");
        on_pushButton_mul_clicked();
        break;
    case Qt::Key_Slash:
        on_pushButton_div_clicked();
        break;
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

