#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T13:12:22
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += no_import_scan qpa_minimal_plugin


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
    NewsList/CWebNewsLoader.cpp \
    NewsList/CWebSiteListModel.cpp

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
    NewsList/CWebNewsLoader.h \
    NewsList/CWebSiteListModel.h

FORMS    += \
    maMainWindow.ui \
    InfoEditor/CInfoEditor.ui \
    NewsList/CNewsListWidget.ui

TRANSLATIONS += translation/myAssistant_zh.ts

RESOURCES += \
    resource/resource.qrc


macx {
    # Prevent qmlplugindump from popping up in the dock when launched.
    # We embed the Info.plist file, so the application doesn't need to
    # be a bundle.
    QMAKE_LFLAGS += -sectcreate __TEXT __info_plist $$shell_quote($$PWD/Info.plist)
    #CONFIG -= app_bundle
    ICON = resource/dragon.icns

    QMAKE_INFO_PLIST = Info.plist
    OTHER_FILES += Info.plist
}

