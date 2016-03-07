#-------------------------------------------------
#
# Project created by QtCreator 2016-03-06T23:45:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task3_3
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    translator.cpp \
    stackPointer.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    translator.h \
    stackPointer.h

FORMS    += mainwindow.ui
