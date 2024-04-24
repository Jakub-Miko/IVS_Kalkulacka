/** @file about.cpp
 * @brief Representation of the "about app" window of the application.
 *
 * This class represents the "about application" window of the application.
 * It contains informations about license, authors, documentation and
 * user manual.
 *
 * @author Patrik Contofalsky, Jakub Miko
*/
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
    QString file_path = QStandardPaths::locate(QStandardPaths::AppDataLocation, "user_guide.pdf", QStandardPaths::LocateOption::LocateFile);
    QDesktopServices::openUrl(QUrl::fromLocalFile(file_path));
}

