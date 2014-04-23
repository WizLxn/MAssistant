#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T13:12:22
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets xml

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
    NewsList/CWebSiteListModel.cpp \
    KindomFight/KingdomFightWindow.cpp \
    KindomFight/KFWorldRunner.cpp \
    KindomFight/KFGraphicsView.cpp \
    KindomFight/KFBaseScene.cpp \
    KindomFight/KFBaseItem.cpp \
    KindomFight/CountryScene/KFCitySurveyScene.cpp \
    KindomFight/Sprite/Sprite.cpp \
    KindomFight/Building/Building.cpp \
    KindomFight/Building/City.cpp \
    KindomFight/DataBase/KFDataBase.cpp \
    KindomFight/KFMain.cpp \
    KindomFight/KFDate.cpp \
    InfoEditor/IELine.cpp \
    MAMisc.cpp

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
    NewsList/CWebSiteListModel.h \
    KindomFight/KingdomFightWindow.h \
    KindomFight/KFWorldRunner.h \
    KindomFight/KFGraphicsView.h \
    KindomFight/KFBaseScene.h \
    KindomFight/KFBaseItem.h \
    KindomFight/CountryScene/KFCitySurveyScene.h \
    KindomFight/Sprite/Sprite.h \
    KindomFight/Building/Building.h \
    KindomFight/Building/City.h \
    KindomFight/DataBase/KFDataBase.h \
    KindomFight/KFMain.h \
    KindomFight/KFDate.h \
    InfoEditor/IELine.h \
    MAMisc.h

FORMS    += \
    maMainWindow.ui \
    InfoEditor/CInfoEditor.ui \
    NewsList/CNewsListWidget.ui \
    KindomFight/KingdomFightWindow.ui

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

