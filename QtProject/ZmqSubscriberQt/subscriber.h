#ifndef CLIENT_H
#define CLIENT_H
#include<QtCore>
#include<QObject>
#include <nzmqt/nzmqt.hpp>
#include <QByteArray>
#include <QList>



using namespace nzmqt;
class Subscriber : public QObject {
    Q_OBJECT
public:
     explicit Subscriber(QObject *parent = 0);
     ~Subscriber();

public slots:
    void process();
    void messageReceived(const QList<QByteArray>& message);

signals:
//    void pingReceived(const QList<QByteArray>& message);
    void finished();
    void error(QString err);
    void requestSent(const QList<QByteArray>& request);
    void replyReceived(const QList<QByteArray>& reply);

private:
    nzmqt::ZMQSocket* mSocket;
    nzmqt::ZMQContext *context;
    QString mTopic;
};

#endif // CLIENT_H
