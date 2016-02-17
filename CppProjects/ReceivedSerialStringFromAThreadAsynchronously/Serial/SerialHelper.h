//
// Created by aknay on 2/17/16.
//

#ifndef BOOSTSIGNALANSSLOTTEST_SERIALHELPER_H
#define BOOSTSIGNALANSSLOTTEST_SERIALHELPER_H

#include "TimeoutSerial.h"
#include <boost/signals2.hpp>

class SerialHelper {

public:
    boost::signals2::signal<void(std::string)> m_signal;
    SerialHelper(const std::string portName, uint baudRate);
    void run();

private:
    TimeoutSerial *serial;
};

#endif //BOOSTSIGNALANSSLOTTEST_SERIALHELPER_H
