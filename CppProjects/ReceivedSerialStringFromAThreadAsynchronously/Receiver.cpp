//
// Created by aknay on 2/17/16.
//


#include "Receiver.h"

void Receiver::onReceived(std::string incomingMsg) {
    std::cout << "Receiver receives: " << incomingMsg << std::endl;
}
