QT += core network gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
    server.cpp \
    serverwindow.cpp \
    ../chatApp.cpp

FORMS += \
    serverwindow.ui \
    serverwindow.ui

HEADERS += \
    server.h \
    serverwindow.h \
    ../chatApp.h
