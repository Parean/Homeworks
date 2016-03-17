QT       += core \
    testlib
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp \
    bubbleSorter.cpp \
    insertionSorter.cpp \
    quickSorter.cpp \
    sorter.cpp

HEADERS += \
    bubbleSorter.h \
    insertionSorter.h \
    quickSorter.h \
    sorter.h \
    sorterTester.h
