QT += core network gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        clientwindow.cpp \
    ../chatApp.cpp \
    client.cpp

HEADERS  += clientwindow.h \
    ../chatApp.h \
    client.h

FORMS    += clientwindow.ui
