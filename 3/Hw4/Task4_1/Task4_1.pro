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
    network/client.cpp \
    network/networkelement.cpp \
    network/server.cpp \
    game/bigcannonball.cpp \
    game/cannon.cpp \
    game/cannonball.cpp \
    game/explosion.cpp \
    game/gamelogic.cpp \
    game/littlecannonball.cpp \
    game/scene.cpp


HEADERS  += mainwindow.h \
    network/client.h \
    network/networkelement.h \
    network/server.h \
    game/bigcannonball.h \
    game/cannon.h \
    game/cannonball.h \
    game/explosion.h \
    game/gamelogic.h \
    game/littlecannonball.h \
    game/scene.h \
    game/scenesize.h


RESOURCES += \
    resources.qrc
