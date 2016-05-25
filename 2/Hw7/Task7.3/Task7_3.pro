QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task7_3
TEMPLATE = app
CONFIG += c++11 console

SOURCES += main.cpp\
	mainwindow.cpp \
    eventhandler.cpp \
    playingbutton.cpp

HEADERS  += mainwindow.h \
    eventhandler.h \
    playingbutton.h \
    eventHandlerTester.h
