#include "CInfoEditorView.h"
#include "CInfoEditorItem.h"
#include <QGraphicsScene>
#include <QMouseEvent>

CInfoEditorView::CInfoEditorView(QWidget *parent) :
    QGraphicsView(parent)
{
    initScene();
}

CInfoEditorItem* CInfoEditorView::findItemAt(const QPoint& point)
{
    CInfoEditorItem* item = dynamic_cast<CInfoEditorItem*>(itemAt(point));
    return item;
}

CInfoEditorItem *CInfoEditorView::findItemAt(int index)
{
    if (index <0 || index >= items().count())
        return 0;

    CInfoEditorItem* item = dynamic_cast<CInfoEditorItem*>(items().at(index));
    return item;
}

void CInfoEditorView::mousePressEvent(QMouseEvent *event)
{
    for (int i = 0; i < items().count(); i++)
    {
        CInfoEditorItem* item = findItemAt(i);
        if (item)
        {
            item->m_itemSelected = false;
        }
    }

    CInfoEditorItem* item = findItemAt(event->pos());
    if (item)
    {
        item->m_itemSelected = true;
    }

    QGraphicsView::mousePressEvent(event);
    scene()->update(scene()->sceneRect());
}

void CInfoEditorView::mouseDoubleClickEvent(QMouseEvent *event)
{
    CInfoEditorItem* item = findItemAt(event->pos());
    if (item)
    {
        QString strText = item->getItemContentText();
        QString strTitle = item->getItemTitle();
        emit showItemText(strTitle, strText);
    }

    QGraphicsView::mouseDoubleClickEvent(event);
}

bool CInfoEditorView::initScene()
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(-300, -300, 600, 600);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < 3; ++i) {
        CInfoEditorItem *mouse = new CInfoEditorItem();
        mouse->setPos(i * 50, i * 30);
        mouse->m_info.strTitle = "strTitle " + QString::number(i);
        mouse->m_info.strContext = "Starting MAssistant-Desktop";
        mouse->m_info.strFontName = "arial";
        mouse->m_info.nFontSize = 5;
        mouse->m_info.nTextMargin = 3;
        mouse->m_boudSize = QSize(60, 200);
        scene->addItem(mouse);
    }

    setScene(scene);

    return true;
}
