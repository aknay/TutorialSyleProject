#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T17:28:34
#
#-------------------------------------------------
QT += 3dcore 3drenderer 3dinput
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shapePlusUi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scenemodifier.cpp \
    view3d.cpp \
    TestCube.cpp

HEADERS  += mainwindow.h \
    scenemodifier.h \
    view3d.h \
    TestCube.h

FORMS    += mainwindow.ui
