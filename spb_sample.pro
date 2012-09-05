#-------------------------------------------------
#
# Project created by QtCreator 2012-07-27T21:50:07
#
#-------------------------------------------------

QT       += core gui

DESTDIR = ../Simple-Property-Browser-for-Qt/bin

TARGET = spb_sample
TEMPLATE = app

include ("spb.pri")




SOURCES += sample/main.cpp\
        sample/cmainwindow.cpp

HEADERS  += sample/cmainwindow.h

FORMS    += sample/cmainwindow.ui
