#ifndef MA_MAINWINDOW_H
#define MA_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MA_MainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MA_MainWindow *ui;
};

#endif // MA_MAINWINDOW_H
