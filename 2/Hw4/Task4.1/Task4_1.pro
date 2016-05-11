QT += testlib
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    hashTable.cpp \
    listPointer.cpp \
    hashRot13.cpp \
    hashLy.cpp \
    hashFaq6.cpp

HEADERS += \
    hashTable.h \
    listPointer.h \
    hashFunction.h \
    hashRot13.h \
    hashLy.h \
    hashFaq6.h \
    hashFunctionTester.h \
    hashTableTester.h
