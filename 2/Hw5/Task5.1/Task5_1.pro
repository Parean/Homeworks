QT += testlib
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += main.cpp \
    operand.cpp \
    operator.cpp

HEADERS += \
    treeNode.h \
    operand.h \
    operator.h \
    treeTester.h
