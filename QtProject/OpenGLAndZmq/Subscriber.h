#ifndef CLIENT_H
#define CLIENT_H
#include<QtCore>
#include<QObject>
#include <nzmqt/nzmqt.hpp>
#include <QByteArray>
#include <QList>

using namespace nzmqt;
class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();

public slots:
    void onMessageReceived(const QList<QByteArray>& message);

signals:
    void receivedData(const QList<QByteArray>&);

private:
    nzmqt::ZMQSocket* mSocket;
    nzmqt::ZMQContext *context;
    QString mTopic;
};

#endif // CLIENT_H
