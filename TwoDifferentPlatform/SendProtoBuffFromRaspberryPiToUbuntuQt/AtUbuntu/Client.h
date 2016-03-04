#ifndef CLIENTTEST_H
#define CLIENTTEST_H

/*Qt header files*/
#include<QtCore>
#include <QObject>
#include <QByteArray>
#include <QList>
#include <QMap>

/*zmq header files*/
#include <nzmqt/nzmqt.hpp>

class Client
        : public QObject
{
    Q_OBJECT
    nzmqt::ZMQContext *mContext;
    nzmqt::ZMQSocket *socket;

public:
    explicit Client(QObject *parent = 0); /*constructor hide in private*/
    void sendMsgToServer();

private slots:
    void onReceivedFromZqmlToConsumeData(QList<QByteArray> receivedMsg);

private:
    void _sendStringToServer(const QString &str);
    void _initilizeConnection();
    QList<QByteArray> _getZmqReadyMsg(const QString &str);
};
#endif // ClientTestTEST_H
