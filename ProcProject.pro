#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T00:41:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProcProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simulation.cpp \
    auth.cpp \
    customeedt.cpp \
    process.cpp \
    splash.cpp

HEADERS  += mainwindow.h \
    simulation.h \
    auth.h \
    customeedt.h \
    process.h \
    splash.h

FORMS    += mainwindow.ui \
    simulation.ui \
    auth.ui \
    splash.ui

RESOURCES += \
    img.qrc \
    accept.qrc \
    timer.qrc \
    lock.qrc \
    auth.qrc \
    delete.qrc \
    qt.qrc \
    arrow.qrc
