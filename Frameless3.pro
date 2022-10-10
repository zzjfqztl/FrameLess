
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug_and_release
CONFIG(debug, debug|release){
    TARGET = ../../_debug/Frameless3
} else {
    TARGET = ../../_release/Frameless3
}

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    FramelessHelper.cpp

HEADERS  += mainwindow.h \
    FramelessHelper.h

FORMS    += mainwindow.ui

RESOURCES += \
    rc.qrc

