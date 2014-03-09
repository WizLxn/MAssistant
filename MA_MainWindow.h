#ifndef MA_MAINWINDOW_H
#define MA_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MA_MainWindow;
}

class MA_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MA_MainWindow(QWidget *parent = 0);
    ~MA_MainWindow();

private:
    Ui::MA_MainWindow *ui;
};

#endif // MA_MAINWINDOW_H
