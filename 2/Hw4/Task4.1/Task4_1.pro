QT += testlib
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    hashTable.cpp \
    listPointer.cpp \
<<<<<<< HEAD
    hashFunction.cpp \
=======
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
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
