#ifndef KFBASESCENE_H
#define KFBASESCENE_H

#include <QGraphicsScene>

enum KFSceneType {
    KFWorldScene,
    KFCountryScene,
    KFCitySurveyScene,
    KFCityInnerScene,
    KFBuildingInnerScene
};

class KFBaseScene : public QGraphicsScene
{
public:
    explicit KFBaseScene(QObject *parent = 0);

    KFSceneType sceneType() const;
    void setSceneType(const KFSceneType &sceneType);

signals:

public slots:

protected:
    KFSceneType m_sceneType;
};

#endif // KFBASESCENE_H
