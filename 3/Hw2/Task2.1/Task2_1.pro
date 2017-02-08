TEMPLATE = app
CONFIG += console c++11
QT += core testlib

SOURCES += main.cpp \
    network.cpp \
    virus.cpp \
    generator/fakegenerator.cpp \
    generator/randomgenerator.cpp \
    computer/computer.cpp


HEADERS += \
    network.h \
    virus.h \
    virustester.h \
    networktester.h \
    computer/computer.h \
    computer/debiancomputer.h \
    computer/ubuntucomputer.h \
    computer/windowscomputer.h \
    generator/fakegenerator.h \
    generator/generator.h \
    generator/randomgenerator.h
