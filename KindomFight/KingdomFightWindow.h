#ifndef KINGDOMFIGHTWINDOW_H
#define KINGDOMFIGHTWINDOW_H

#include <QMainWindow>

namespace Ui {
class KingdomFightWindow;
}

class KFDataBase;
class KingdomFightWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KingdomFightWindow(KFDataBase *database, QWidget *parent = 0);
    ~KingdomFightWindow();

    //
    void showTextMessage(const QString& strMsg);
private:
    Ui::KingdomFightWindow *ui;
    KFDataBase *m_dbConn;
};

#endif // KINGDOMFIGHTWINDOW_H
