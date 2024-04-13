#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

