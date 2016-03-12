QT       += core \
    testlib
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp \
    listArray.cpp \
    listPointer.cpp

HEADERS += \
    list.h \
    listArray.h \
    listPointer.h \
    listTester.h
