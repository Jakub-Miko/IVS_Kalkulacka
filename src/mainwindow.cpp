#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), mode_choice(true)
{
    ui->setupUi(this);
    setWindowTitle("E-Calculator");


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
    connect(ui->pushButton_comma, SIGNAL(released()), this, SLOT(number_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::number_clicked()
{
    QPushButton * Button = (QPushButton*)sender();

    QString LabelNumber;

    LabelNumber = (ui->display->text() + Button->text());
    ui->display->setText(LabelNumber);
    ui->display->setAlignment(Qt::AlignRight);

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
    ui->equation->setText("");
}


void MainWindow::on_pushButton_cleardisp_released()
{
    ui->display->setText("");
}

void MainWindow::keyReleaseEvent(QKeyEvent * event)
{
    QString LabelNumber;
    QString NextNumber = "";
    if (event->key() == Qt::Key_0) {
        NextNumber = "0";
    } else if (event->key() == Qt::Key_1) {
        NextNumber = "1";
    } else if (event->key() == Qt::Key_2) {
        NextNumber = "2";
    } else if (event->key() == Qt::Key_3) {
        NextNumber = "3";
    } else if (event->key() == Qt::Key_4) {
        NextNumber = "4";
    } else if (event->key() == Qt::Key_5) {
        NextNumber = "5";
    } else if (event->key() == Qt::Key_6) {
        NextNumber = "6";
    } else if (event->key() == Qt::Key_7) {
        NextNumber = "7";
    } else if (event->key() == Qt::Key_8) {
        NextNumber = "8";
    } else if (event->key() == Qt::Key_9) {
        NextNumber = "9";
    } else if (event->key() == Qt::Key_Backspace) {
        LabelNumber = (ui->display->text());
        LabelNumber.chop(1);
        ui->display->setText(LabelNumber);
    } else if (event->key() == Qt::Key_Delete) {
        ui->display->setText("");
    }
    LabelNumber = (ui->display->text() + NextNumber);
    ui->display->setText(LabelNumber);
}

void MainWindow::on_actionSettings_triggered()
{
    settings_window = new settings(this);
    settings_window->show();
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

