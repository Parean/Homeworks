TEMPLATE = app
CONFIG += console c++11
QT += core testlib

SOURCES += main.cpp \
    network.cpp \
    virus.cpp

HEADERS += \
    computer.h \
    windowscomputer.h \
    ubuntucomputer.h \
    debiancomputer.h \
    network.h \
    virus.h \
    virustester.h \
    networktester.h
