QT       += core \
    testlib
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp \
    listPointer.cpp \
    listsComparator.cpp \
    sortedSet.cpp

HEADERS += \
    listPointer.h \
    listsComparator.h \
    sortedSet.h \
    setTester.h \
    listTester.h
