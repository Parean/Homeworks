TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    outputer.cpp \
    consolOutputer.cpp \
    fileOutputer.cpp

HEADERS += \
    consolOutputer.h \
    fileOutputer.h \
    outputer.h

DISTFILES += \
    text.txt
