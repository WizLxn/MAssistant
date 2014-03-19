#ifndef CINFOEDITORVIEW_H
#define CINFOEDITORVIEW_H

#include <QGraphicsView>

class CInfoEditorView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CInfoEditorView(QWidget *parent = 0);

signals:

public slots:

private:
    bool initScene();
};

#endif // CINFOEDITORVIEW_H
