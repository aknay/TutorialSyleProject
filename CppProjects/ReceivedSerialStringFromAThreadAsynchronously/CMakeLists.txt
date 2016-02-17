cmake_minimum_required(VERSION 3.3)
project(ReceivedSerialStringFromAThreadAsynchronously)

FIND_PACKAGE( Boost 1.60 COMPONENTS system thread REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Serial/TimeoutSerial.cpp Serial/TimeoutSerial.h Serial/SerialHelper.cpp Serial/SerialHelper.h  Receiver.cpp Receiver.h)
add_executable(ReceivedSerialStringFromAThreadAsynchronously ${SOURCE_FILES} )
target_link_libraries(ReceivedSerialStringFromAThreadAsynchronously ${Boost_LIBRARIES} -lpthread)