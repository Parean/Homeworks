TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    listPointer.cpp \
    listsComparator.cpp \
    sortedSet.cpp

HEADERS += \
    listPointer.h \
    listsComparator.h \
    sortedSet.h
