#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMediaDevices>
#include <QAudioDevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), mode_choice(true), player(nullptr), output(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("E-Calculator");

    if(!QMediaDevices::defaultAudioOutput().isNull()) {
        output = new QAudioOutput(this);
	    player = new QMediaPlayer(this);
    }
    
    connect(ui->pushButton_number_0, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_1, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_2, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_3, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_4, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_5, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_6, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_7, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_8, SIGNAL(released()), this, SLOT(number_clicked()));
    connect(ui->pushButton_number_9, SIGNAL(released()), this, SLOT(number_clicked()));

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
    player->setSource(QUrl("qrc:/It's in the game.mp3"));
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
    ui->display->setAlignment(Qt::AlignRight);

}

void AddNumber(Ui::MainWindow* ui, QString NextNumber) {
    QString LabelNumber;
    LabelNumber = (ui->display->text() + NextNumber);
    ui->display->setText(LabelNumber);
}

QString ReplaceString(QString Text, QString Find, QString Replace) {
    Text.replace(Find, Replace);
    return Text;
}

void convert() {

}

void MainWindow::on_pushButton_backspace_released()
{
    QString LabelNumber;
    LabelNumber = (ui->display->text());
    LabelNumber.chop(1);
    ui->display->setText(LabelNumber);
}

void MainWindow::on_pushButton_clearfull_released()
{
    ui->display->setText("");
    ui->equation->setText("0");
    math.ResetAllContexts();
}


void MainWindow::on_pushButton_cleardisp_released()
{
    ui->display->setText("");
}

void MainWindow::keyReleaseEvent(QKeyEvent * event)
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
    case Qt::Key_Comma:
    case Qt::Key_Period:
        on_pushButton_comma_released();
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
    if (ui->display->text() == "") {
        qInfo("Pekne menis znamienko :3");
        switch(event->key()) {
        case Qt::Key_Plus:
            math.SendAdd();
            break;
        case Qt::Key_Minus:
            math.SendSubtract();
            break;
        case Qt::Key_Asterisk:
            math.SendMultiply();
            break;
        case Qt::Key_Slash:
            math.SendDivide();
            break;
        }
    } else
    switch(event->key()) {
    case Qt::Key_Plus:
        on_pushButton_plus_released();
        break;
    case Qt::Key_Minus:
        on_pushButton_minus_released();
        break;
    case Qt::Key_Asterisk:
        qInfo("More");
        on_pushButton_mul_released();
        break;
    case Qt::Key_Slash:
        on_pushButton_div_released();
        break;
    case Qt::Key_Enter:
        on_pushButton_equals_released();
        break;
    }
}


void MainWindow::on_actionAbout_triggered()
{
    about_window = new about(this);
    about_window->show();
}

void MainWindow::on_pushButton_mode_released()
{
    ui->MOD_container->setCurrentIndex(mode_choice);
    if(mode_choice) mode_choice = false;
    else mode_choice = true;
}


void MainWindow::on_pushButton_plus_released()
{
    try {
    long double ld = std::strtold(ui->display->text().toLatin1().data(),nullptr);
    math.SendNumber(ld);
    math.SendAdd();
    ld = math.GetAccumulator();
    ui->equation->setText(QString::number((double)ld,'g',40));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_minus_released()
{
    try {
        long double ld = std::strtold(ReplaceString(ui->display->text(), ".", ",").toLatin1().data(), nullptr);
        //long double ld = std::strtold(ui->display->text().toLatin1().data(),nullptr);
        math.SendNumber(ld);
        math.SendSubtract();
        ld = math.GetAccumulator();
        ui->equation->setText(QString::number((double)ld,'g',40));
        ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_mul_released()
{
    try {
    math.SendNumber(1);
    long double ld = std::strtold(ui->display->text().toLatin1().data(),nullptr);
    math.SendNumber(ld);
    math.SendMultiply();
    ld = math.GetAccumulator();
    ui->equation->setText(QString::number((double)ld,'g',40));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_div_released()
{
    try {
    long double ld = std::strtold(ui->display->text().toLatin1().data(),nullptr);
    math.SendNumber(ld);
    math.SendDivide();
    ld = math.GetAccumulator();
    ui->equation->setText(QString::number((double)ld,'g',40));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_equals_released()
{
    try {
    long double ld = std::strtold(ReplaceString(ui->display->text(), ",", ".").toLatin1().data(), nullptr);
    math.SendNumber(ld);
    math.SendEquals();
    ld = math.GetAccumulator();
    ui->equation->setText(ReplaceString(QString::number((double)ld,'g',40), ".", ","));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_comma_released()
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



void MainWindow::on_pushButton_root_released()
{
    try {
    long double ld = std::strtold(ui->display->text().toLatin1().data(),nullptr);
    math.SendNumber(ld);
    math.SendRoot();
    ld = math.GetAccumulator();
    ui->equation->setText(QString::number((double)ld,'g',40));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_power_released()
{
    try {
    long double ld = std::strtold(ui->display->text().toLatin1().data(),nullptr);
    math.SendNumber(ld);
    math.SendPower();
    ld = math.GetAccumulator();
    ui->equation->setText(QString::number((double)ld,'g',40));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }

}


void MainWindow::on_pushButton_abs_released()
{
    try {
    math.SendAbsVal();
    long double ld = math.GetAccumulator();
    ui->equation->setText(QString::number((double)ld,'g',40));
    ui->display->setText("");
    } catch(const std::runtime_error& err) {
        qDebug() << err.what();
    }
}


void MainWindow::on_pushButton_pi_released()
{
    ui->display->setText(ReplaceString(QString::number((double)constants::const_pi, 'F', 40), ".", ","));
}


void MainWindow::on_pushButton_c_released()
{
    //ui->display->setText(QString::number((double)constants::const_c, 'F', 40));
}


void MainWindow::on_pushButton_e_released()
{
    ui->display->setText(ReplaceString(QString::number((double)constants::const_e, 'F', 40),".", ","));
}


void MainWindow::on_pushButton_k_released()
{
    ui->display->setText(ReplaceString(QString::number((double)constants::const_k, 'F', 40),".", ","));
}


void MainWindow::on_pushButton_h_released()
{
    ui->display->setText(ReplaceString(QString::number((double)constants::const_h, 'F', 40),".", ","));

}

