#include "Client.h"
#include "message.pb.h" //load protobuff header
#include <iostream>
using namespace std;

using namespace nzmqt;

Client::Client(QObject *parent) :
    QObject(parent), mContext(createDefaultContext(parent))
{
    //setup network ip address and connect
    QString raspberryPiAddress = "192.168.1.104";
    _initilizeConnection();

    const int portNumber = 5556;
    QString stringPortNumber = QString::number(portNumber);

    QString ipAddressString = "tcp://" + raspberryPiAddress.toLocal8Bit() + ":" +stringPortNumber.toLocal8Bit();
    QByteArray qByteArray = ipAddressString.toLatin1();
    const char *charIpAddress = qByteArray.data();

    socket->connectTo(charIpAddress);
}

void Client::sendMsgToServer()
{
    message::AddressBook addressBook;

    message::Person *john = addressBook.add_person();
    john->set_name("John ");
    john->set_email("john@abc.com");

    message::Person *drake = addressBook.add_person();
    drake->set_name("Drake");
    drake->set_email("drake@abc.com");

    qDebug() << "Number of Person in Address Book: " << addressBook.person_size();

    //Checking our data before we send to server
    for (message::Person person : addressBook.person()) {
        qDebug() << "Hello " << person.name().c_str();
        qDebug() << "Your email will be " << person.email().c_str();
    }

    std::string msg_str;
    addressBook.SerializeToString(&msg_str); //serialize to string first
    _sendStringToServer(msg_str.c_str());
}


void Client::onReceivedFromZqmlToConsumeData(QList<QByteArray> receivedMsg)
{
    /**
     * This function will be called when data is recieved from server
    */

    QString receivedMsgstring = receivedMsg.at(0);
    qDebug() << "Received Msg from Server is " <<receivedMsgstring;
}


void Client::_sendStringToServer(const QString &str)
{
    QList<QByteArray> msg = _getZmqReadyMsg(str);
    socket->sendMessage(msg);
}

void Client::_initilizeConnection()
{
    socket = mContext->createSocket(ZMQSocket::TYP_REQ, this);
    QObject::connect(socket, SIGNAL(messageReceived(QList<QByteArray>)),
                     SLOT(onReceivedFromZqmlToConsumeData(QList<QByteArray>)));
    mContext->start();
}

QList<QByteArray> Client::_getZmqReadyMsg(const QString &str)
{
    QList<QByteArray> msg;
    msg << str.toUtf8();
    return msg;
}
