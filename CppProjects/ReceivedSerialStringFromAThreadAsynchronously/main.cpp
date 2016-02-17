#include <boost/thread.hpp>
#include "Receiver.h"
#include "Serial/SerialHelper.h"

int main(int argc, char *argv[]) {
    Receiver r;
    try {

        SerialHelper serialHelper("/dev/ttyACM0", 9600);
        serialHelper.m_signal.connect(boost::bind(&Receiver::onReceived, r, _1));
        boost::thread thread(&SerialHelper::run, &serialHelper);
        thread.join();
    }
    catch (boost::system::system_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
}














