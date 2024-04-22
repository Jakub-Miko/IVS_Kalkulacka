#include "about.h"
#include "qdesktopservices.h"
#include "ui_about.h"

#include <QStandardPaths>

about::about(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::about)
{
    ui->setupUi(this);
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    QString file_path = QStandardPaths::locate(QStandardPaths::AppDataLocation, "LICENSE", QStandardPaths::LocateOption::LocateFile);
    QDesktopServices::openUrl(QUrl::fromLocalFile(file_path));
}

