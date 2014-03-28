#ifndef CNEWSLISTWIDGET_H
#define CNEWSLISTWIDGET_H

#include <QWidget>

namespace Ui {
class CNewsListWidget;
}

class CWebSiteListModel;
class CNewsListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CNewsListWidget(QWidget *parent = 0);
    ~CNewsListWidget();

private slots:
    void on_Btn_update_clicked();

    void on_Btn_add_clicked();

    void on_btn_edit_clicked();

    void on_Btn_delete_clicked();

    void on_Btn_OK_clicked();

    void on_newsLoadFinished(QString webSite, QStringList newsList);
private:
    Ui::CNewsListWidget *ui;
    CWebSiteListModel* m_webSiteModel;
};

#endif // CNEWSLISTWIDGET_H
