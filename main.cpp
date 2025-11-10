#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow w2;
    w.resize(600,400);
    w2.resize(600,400);
    w.move(300,300);
    w2.move(900,300);
    w.show();
    w2.show();
    return a.exec();
}
