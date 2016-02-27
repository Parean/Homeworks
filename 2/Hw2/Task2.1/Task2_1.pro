TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bubbleSorter.cpp \
    insertionSorter.cpp \
    quickSorter.cpp \
    sorter.cpp

HEADERS += \
    bubbleSorter.h \
    insertionSorter.h \
    quickSorter.h \
    sorter.h
