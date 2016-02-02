#-------------------------------------------------
#
# Project created by QtCreator 2016-01-28T17:17:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = circlesDSSL
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    circle.cpp \
    settlements.cpp \
    paintwidget.cpp \
    customcurve.cpp

HEADERS  += mainwindow.h \
    circle.h \
    settlements.h \
    paintwidget.h \
    customcurve.h

FORMS    += mainwindow.ui
