#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/resources/impact.ttf");
    MainWindow w;
    w.show();
    std::cerr << "Window Opened" << std::endl;
    return a.exec();
}
