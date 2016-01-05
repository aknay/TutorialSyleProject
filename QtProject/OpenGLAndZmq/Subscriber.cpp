#include "Subscriber.h"

Subscriber::Subscriber(QObject *parent) :
    QObject(parent)
{
    context = nzmqt::createDefaultContext(this);
    context->start();
    mSocket = context->createSocket(ZMQSocket::TYP_SUB, this);
    mSocket->connectTo("tcp://127.0.0.1:5556");
    mSocket->subscribeTo(mTopic);
    connect(mSocket, SIGNAL(messageReceived(const QList<QByteArray>&)), SLOT(onMessageReceived(const QList<QByteArray>&)));

}
Subscriber::~Subscriber(){
}


void Subscriber::onMessageReceived(const QList<QByteArray>& message){
    qDebug() << "Subscriber> " << message;
    /*emit the signal from Subscriber once the signal is received from Socket*/
    emit receivedData(message);
}

