#include "KFBaseScene.h"

KFBaseScene::KFBaseScene(QObject *parent) :
    QGraphicsScene(parent)
{
}
KFSceneType KFBaseScene::sceneType() const
{
    return m_sceneType;
}

void KFBaseScene::setSceneType(const KFSceneType &sceneType)
{
    m_sceneType = sceneType;
}

