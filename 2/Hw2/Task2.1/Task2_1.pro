<<<<<<< HEAD
QT       += core \
    testlib
TEMPLATE = app
CONFIG += console c++11
=======
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8

SOURCES += main.cpp \
    bubbleSorter.cpp \
    insertionSorter.cpp \
    quickSorter.cpp \
    sorter.cpp

HEADERS += \
    bubbleSorter.h \
    insertionSorter.h \
    quickSorter.h \
<<<<<<< HEAD
    sorter.h \
    sorterTester.h
=======
    sorter.h
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
