#-------------------------------------------------
#
# Project created by QtCreator 2015-12-28T13:24:25
#
#-------------------------------------------------

!include( nzmqt.pri ) {
    error( "Couldn't find the nzmqt.pri file!" )
}



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZmqClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subscriber.cpp

HEADERS  += mainwindow.h \
    subscriber.h

LIBS += -lzmq

FORMS    += mainwindow.ui

#DISTFILES += \
#    nzmqt.pri
