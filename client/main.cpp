#include "mainwindow.h"
#include "network.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    NetWork network;
    network.createSocketAndConnect();

    QApplication a(argc, argv);
    MainWindow w(network);
    w.show();
    return a.exec();
}
