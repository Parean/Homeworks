TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    firstclass.cpp \
    secondclass.cpp \
    exception.cpp

HEADERS += \
    firstclass.h \
    secondclass.h \
    exception.h
