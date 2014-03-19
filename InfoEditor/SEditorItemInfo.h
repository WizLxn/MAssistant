#ifndef SEDITORITEMINFO_H
#define SEDITORITEMINFO_H

#include <QString>
#include <QColor>

struct SEditorItemInfo
{
    QString strGUID;
    QString strTitle;
    QString strContext;

    QString strFontName;
    int nFontSize;
    int nTextMargin;
    QColor clFontColor;
};

#endif // SEDITORITEMINFO_H
