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
    maWindowStyle.cpp \
    maMAssistant.cpp \
    maTimedReminder.cpp \
    InfoEditor/CInfoEditor.cpp \
    InfoEditor/CInfoEditorView.cpp \
    InfoEditor/CInfoEditorItem.cpp

HEADERS  += \
    maMainWindow.h \
    maTrayIcon.h \
    maMAssistant.h \
    maWindowStyle.h \
    maTimedReminder.h \
    InfoEditor/CInfoEditor.h \
    InfoEditor/CInfoEditorView.h \
    InfoEditor/CInfoEditorItem.h \
    InfoEditor/SEditorItemInfo.h

FORMS    += \
    maMainWindow.ui \
    InfoEditor/CInfoEditor.ui

TRANSLATIONS += translation/myAssistant_zh.ts

RESOURCES += \
    resource/resource.qrc
