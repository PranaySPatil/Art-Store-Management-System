#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T21:12:17
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui network widgets

TARGET = ArtStoreMangementSystem
TEMPLATE = app

INCLUDEPATH = C:/libxl-3.6.5.0/include_cpp
LIBS += C:/libxl-3.6.5.0/lib/libxl.lib

SOURCES += main.cpp\
        mainwindow.cpp \
    loginform.cpp \
    buyform.cpp \
    sellform.cpp \
    reportform.cpp \
    customlistitemform.cpp \
    aboutform.cpp \
    profileform.cpp

HEADERS  += mainwindow.h \
    loginform.h \
    buyform.h \
    sellform.h \
    reportform.h \
    customlistitemform.h \
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

RC_FILE = asms.rc
