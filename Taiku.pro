#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T21:26:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    ball.cpp \
    gametime.cpp \
    score.cpp

HEADERS  += mainwindow.h \
    scene.h \
    ball.h \
    gametime.h \
    score.h

FORMS    += mainwindow.ui
