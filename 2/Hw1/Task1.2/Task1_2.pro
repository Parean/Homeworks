TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    calculator.cpp \
    stackArray.cpp \
    stackPointer.cpp \
    translator.cpp

HEADERS += \
    calculator.h \
    stack.h \
    stackArray.h \
    stackPointer.h \
    translator.h
