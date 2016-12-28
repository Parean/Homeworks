#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T17:56:18
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task4_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cannon.cpp \
    cannonball.cpp \
    gamelogic.cpp \
    littlecannonball.cpp \
    scene.cpp \
    bigcannonball.cpp \
    networkelement.cpp \
    client.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    cannon.h \
    cannonball.h \
    gamelogic.h \
    littlecannonball.h \
    scene.h \
    scenesize.h \
    bigcannonball.h \
    networkelement.h \
    client.h \
    server.h

RESOURCES += \
    resources.qrc
