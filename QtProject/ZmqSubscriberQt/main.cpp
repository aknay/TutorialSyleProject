#include "mainwindow.h"
#include <QApplication>
#include<QtCore>
#include"subscriber.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug()<<"From main thread: "<<QThread::currentThreadId();
    QThread *thread = new QThread();
    Subscriber *subscriber= new Subscriber();
     subscriber->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()), subscriber, SLOT(process()));
    QObject::connect(subscriber, SIGNAL (finished()), thread, SLOT(quit()));
    thread->start();

    return a.exec();
}
