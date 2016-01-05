#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T17:28:34
#
#-------------------------------------------------

!include( nzmqt.pri ) {
    error( "Couldn't find the nzmqt.pri file!" )
}

QT += 3dcore 3drenderer 3dinput
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = shapePlusUi
TARGET = OpenGLandZmq
TEMPLATE = app


SOURCES += main.cpp\
    SceneModifier.cpp \
    MainWindow.cpp \
    Subscriber.cpp \
    CubeObject.cpp \
    View3d.cpp

HEADERS  += \
    SceneModifier.h \
    Subscriber.h \
    MainWindow.h \
    CubeObject.h \
    View3d.h

LIBS += -lzmq

FORMS    += mainwindow.ui

DISTFILES += \
    nzmqt.pri
