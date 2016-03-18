#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T21:12:17
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui network widgets

TARGET = ArtStoreMangementSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginform.cpp \
    buyform.cpp \
    sellform.cpp \
    reportform.cpp \
    customlistitemform.cpp \
    reportitem.cpp \
    aboutform.cpp \
    profileform.cpp

HEADERS  += mainwindow.h \
    loginform.h \
    buyform.h \
    sellform.h \
    reportform.h \
    customlistitemform.h \
    reportitem.h \
    aboutform.h \
    profileform.h

FORMS    += mainwindow.ui \
    loginform.ui \
    buyform.ui \
    sellform.ui \
    reportform.ui \
    customlistitemform.ui \
    aboutform.ui \
    profileform.ui
