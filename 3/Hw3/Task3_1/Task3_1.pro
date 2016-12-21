#-------------------------------------------------
#
# Project created by QtCreator 2016-12-17T18:44:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task3_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    gamelogic.cpp \
    cannon.cpp \
    littlecannonball.cpp \
    cannonball.cpp

HEADERS  += mainwindow.h \
    scene.h \
    gamelogic.h \
    cannon.h \
    scenesize.h \
    cannonball.h \
    littlecannonball.h

RESOURCES += \
    resources.qrc
