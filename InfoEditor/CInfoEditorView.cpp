#include "CInfoEditorView.h"
#include <QGraphicsScene>
#include "CInfoEditorItem.h"

CInfoEditorView::CInfoEditorView(QWidget *parent) :
    QGraphicsView(parent)
{
    initScene();
}

bool CInfoEditorView::initScene()
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(-300, -300, 600, 600);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < 3; ++i) {
        CInfoEditorItem *mouse = new CInfoEditorItem();
        mouse->setPos(i * 50, i * 30);
        mouse->m_info.strTitle = "strTitle";
        mouse->m_info.strContext = "Starting /Users/lxn/Program/build-MAssistant-Desktop";
        mouse->m_info.strFontName = "arial";
        mouse->m_info.nFontSize = 5;
        mouse->m_info.nTextMargin = 3;
        mouse->m_boudSize = QSize(60, 200);
        scene->addItem(mouse);
    }

    setScene(scene);

    return true;
}
