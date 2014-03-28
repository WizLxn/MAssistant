#ifndef MAMASSISTANT_H
#define MAMASSISTANT_H

#include <QObject>
#include <QList>

class CTrayIcon;
class CMainWindow;
class CTimedReminder;
class CMAssistant : public QObject
{
    Q_OBJECT
public:
    explicit CMAssistant(CTrayIcon& traIcon, CMainWindow& window, QObject *parent = 0);
    ~CMAssistant();

    void showTrayIcon();
    void showMainWindow();
signals:

public slots:

private:

    CTrayIcon& m_trayIcon;
    CMainWindow& m_mainWindow;
    QList<CTimedReminder*> m_timedReminders;

};

#endif // MAMASSISTANT_H
