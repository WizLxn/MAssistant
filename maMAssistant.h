#ifndef MAMASSISTANT_H
#define MAMASSISTANT_H

#include <QObject>
#include <QList>

class CTrayIcon;
class CMainwindow;
class CTimedReminder;
class CMAssistant : public QObject
{
    Q_OBJECT
public:
    explicit CMAssistant(CTrayIcon& traIcon, CMainwindow& window, QObject *parent = 0);
    ~CMAssistant();
signals:

public slots:

private:
    CTrayIcon& m_trayIcon;
    CMainwindow& m_mainWindow;
    QList<CTimedReminder*> m_timedReminders;
};

#endif // MAMASSISTANT_H
