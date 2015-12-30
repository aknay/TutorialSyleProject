#include "subscriber.h"

Subscriber::Subscriber(QObject *parent) :
    QObject(parent)
{
context = nzmqt::createDefaultContext(this);
context->start();
mSocket = context->createSocket(ZMQSocket::TYP_SUB, this);
mSocket->connectTo("tcp://127.0.0.1:5556");
mSocket->subscribeTo(mTopic);
connect(mSocket, SIGNAL(messageReceived(const QList<QByteArray>&)), SLOT(messageReceived(const QList<QByteArray>&)));

}
Subscriber::~Subscriber(){

}


void Subscriber::messageReceived(const QList<QByteArray>& message)
{
    qDebug() << "Subscriber> " << message;
}


void Subscriber::process(){
qDebug("Scubscriber started");
}

