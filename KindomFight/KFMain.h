#ifndef KFMAIN_H
#define KFMAIN_H

#include <QObject>

class KFDataBase;
class KFWorldRunner;
class KingdomFightWindow;
class KFMain : public QObject
{
    Q_OBJECT
public:
    KFMain(QObject* parent = 0);
    void showKFMainWindow();
    void closeMainWindow();
signals:
    void mainWindowClosed();

public slots:
    void on_mainWindowClosed();

private:
    KFDataBase *m_db;
    KFWorldRunner *m_runner;
    KingdomFightWindow *m_mainWindow;
};



#endif // KFMAIN_H
