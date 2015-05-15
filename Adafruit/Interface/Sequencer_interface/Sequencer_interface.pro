#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T11:26:57
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

CONFIG   += serial port
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sequencer_interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
