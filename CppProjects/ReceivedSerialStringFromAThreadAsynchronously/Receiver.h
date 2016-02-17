//
// Created by aknay on 2/17/16.
//

#ifndef BOOSTSIGNALANSSLOTTEST_RECEIVER_H
#define BOOSTSIGNALANSSLOTTEST_RECEIVER_H

#include <iostream>

class Receiver {
public:
    void onReceived(std::string incomingMsg);
};

#endif //BOOSTSIGNALANSSLOTTEST_RECEIVER_H