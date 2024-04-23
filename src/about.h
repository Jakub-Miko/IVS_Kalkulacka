/** @file about.h
 * @brief Representation of the "about app" window of the application.
 *
 * This class represents the "about application" window of the application.
 * It contains informations about license, authors, documentation and
 * user manual.
 *
 * @author Patrik Contofalsky, Jakub Miko
*/
#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

private slots:
    void on_pushButton_clicked();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
