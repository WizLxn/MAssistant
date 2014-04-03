#ifndef CINFOEDITORVIEW_H
#define CINFOEDITORVIEW_H

#include <QGraphicsView>

class CInfoEditorItem;
class CInfoEditorView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CInfoEditorView(QWidget *parent = 0);

    //void appendItem()
    CInfoEditorItem* findItemAt(const QPoint& point);
    CInfoEditorItem* findItemAt(int index);
signals:
    void showItemText(QString strText);
public slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    bool initScene();
};

#endif // CINFOEDITORVIEW_H
