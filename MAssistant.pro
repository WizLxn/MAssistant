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
    maTrayIcon.cpp \
    maMainWindow.cpp \
    maMAssistant.cpp \
    maWindowStyle.cpp

HEADERS  += \
    maMainWindow.h \
    maTrayIcon.h \
    maMAssistant.h \
    maWindowStyle.h

FORMS    += \
    maMainWindow.ui

TRANSLATIONS += translation/myAssistant_zh.ts

RESOURCES += \
    resource/resource.qrc
