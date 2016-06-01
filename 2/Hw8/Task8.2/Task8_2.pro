#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T00:37:33
#
#-------------------------------------------------

QT       += core gui network webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task8_2
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
	widget.cpp \
    bash.cpp \
    quote.cpp

HEADERS  += widget.h \
    bash.h \
    quote.h

FORMS    += widget.ui
