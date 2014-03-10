#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T13:12:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MAssistant
TEMPLATE = app


SOURCES += main.cpp\
        MA_MainWindow.cpp \
    MA_TrayIcon.cpp

HEADERS  += MA_MainWindow.h \
    MA_TrayIcon.h

FORMS    += MA_MainWindow.ui

TRANSLATIONS += translation/myAssistant_zh.ts

RESOURCES += \
    resource/resource.qrc
