#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include "Client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Client clientTest;
    clientTest.sendMsgToServer();

    return a.exec();
}
