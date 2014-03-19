#ifndef CINFOEDITOR_H
#define CINFOEDITOR_H

#include <QMainWindow>

namespace Ui {
class CInfoEditor;
}

class CInfoEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CInfoEditor(QWidget *parent = 0);
    ~CInfoEditor();

private:
    Ui::CInfoEditor *ui;
};

#endif // CINFOEDITOR_H
