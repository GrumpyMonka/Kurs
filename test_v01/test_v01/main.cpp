#include "mainwindow.h"

#include <QApplication>
#include <QGroupBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //w.showFullScreen();

    return a.exec();
}
