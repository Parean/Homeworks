QT       += core \
    testlib
TEMPLATE = app
CONFIG += console c++11

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
    translator.h \
    stackTester.h \
    translatorTester.h \
    calculatorTester.h
