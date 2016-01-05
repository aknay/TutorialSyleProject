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
    void onMessageReceived(const QList<QByteArray>& message);

signals:
    void receivedData(const QList<QByteArray>&);

private:
    nzmqt::ZMQSocket* mSocket;
    nzmqt::ZMQContext *context;
    QString mTopic;
};

#endif // CLIENT_H
