#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T13:12:22
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

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
    InfoEditor/CInfoEditorItem.cpp \
    NewsList/CNewsListWidget.cpp \
    NewsList/CWebSiteItemDelegate.cpp \
    NewsList/CNewsViewStyle.cpp \
    NewsList/CNewsListItem.cpp \
    NewsList/CGetWebPageNews.cpp \
    NewsList/CWebNewsLoader.cpp

HEADERS  += \
    maMainWindow.h \
    maTrayIcon.h \
    maMAssistant.h \
    maWindowStyle.h \
    maTimedReminder.h \
    InfoEditor/CInfoEditor.h \
    InfoEditor/CInfoEditorView.h \
    InfoEditor/CInfoEditorItem.h \
    InfoEditor/SEditorItemInfo.h \
    NewsList/CNewsListWidget.h \
    NewsList/CWebSiteItemDelegate.h \
    NewsList/CNewsViewStyle.h \
    NewsList/CNewsListItem.h \
    NewsList/CGetWebPageNews.h \
    NewsList/CWebNewsLoader.h

FORMS    += \
    maMainWindow.ui \
    InfoEditor/CInfoEditor.ui \
    NewsList/CNewsListWidget.ui

TRANSLATIONS += translation/myAssistant_zh.ts

RESOURCES += \
    resource/resource.qrc
