#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T13:24:25
#
#-------------------------------------------------

!include( nzmqt.pri ) {
    error( "Couldn't find the nzmqt.pri file!" )
}

!include( protobuff.pri ) {
    error( "Couldn't find the protobuff.pri file!" )
}


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++0x

TARGET = ZmqClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Client.cpp

HEADERS  += mainwindow.h \
    Client.h

#For Zmq
LIBS += -lzmq

#For ProtoBuff
LIBS += /usr/local/lib/libprotobuf.so
PROTOS = message.proto


FORMS    += mainwindow.ui

#DISTFILES += \
#    nzmqt.pri
