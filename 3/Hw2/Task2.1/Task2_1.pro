TEMPLATE = app
CONFIG += console c++11
QT += core testlib

SOURCES += main.cpp \
    network.cpp \
    computer/computer.cpp \
    infectionchecker/randominfectionchecker.cpp \
    infectionchecker/testinfectionchecker.cpp


HEADERS += \
    network.h \
    networktester.h \
    computer/computer.h \
    computer/debiancomputer.h \
    computer/ubuntucomputer.h \
    computer/windowscomputer.h \
    infectionchecker/randominfectionchecker.h \
    infectionchecker/infectionchecker.h \
    infectionchecker/testinfectionchecker.h

DISTFILES +=
