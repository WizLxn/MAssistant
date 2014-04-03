#ifndef CINFOEDITOR_H
#define CINFOEDITOR_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class CInfoEditor;
}

class QAction;
class CInfoEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CInfoEditor(QWidget *parent = 0);
    ~CInfoEditor();

public slots:
    void displayItemInfo(QString strTitle, QString strText);

private:
    void initToolBar();

private:
    Ui::CInfoEditor *ui;

    QAction* m_actionAddItem;
};

#endif // CINFOEDITOR_H
