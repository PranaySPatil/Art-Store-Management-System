#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T21:12:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArtStoreMangementSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginform.cpp \
    buyform.cpp \
    sellform.cpp \
    reportform.cpp

HEADERS  += mainwindow.h \
    loginform.h \
    buyform.h \
    sellform.h \
    reportform.h

FORMS    += mainwindow.ui \
    loginform.ui \
    buyform.ui \
    sellform.ui \
    reportform.ui
