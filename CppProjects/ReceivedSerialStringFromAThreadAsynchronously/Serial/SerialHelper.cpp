//
// Created by aknay on 2/17/16.
//

#include <iostream>
#include "SerialHelper.h"

void SerialHelper::run() {
    while (1) {
        std::string receivedString = serial->readStringUntil("\r\n");
        std::cout << "Emitter send: " << receivedString << std::endl;
        m_signal(receivedString);
    }
}

SerialHelper::SerialHelper(const std::string portName, uint baudRate) {
    serial = new TimeoutSerial(portName, baudRate);
    serial->setTimeout(boost::posix_time::seconds(5)); //just make it default for now
}