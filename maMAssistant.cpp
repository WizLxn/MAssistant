#include "maMAssistant.h"
#include "maTimedReminder.h"
#include "maMainWindow.h"
#include "maTrayIcon.h"

CMAssistant::CMAssistant(CTrayIcon& traIcon, CMainWindow& window, QObject* parent) :
    QObject(parent),
    m_trayIcon(traIcon),
    m_mainWindow(window)
{
    CTimedReminder* reminder = new CTimedReminder(this);
    connect(reminder, SIGNAL(timeToRemid(QString)), &m_trayIcon, SLOT(on_message_remind(QString)));
    m_timedReminders.append(reminder);
    reminder->startReminder(20 * 60, 20, tr("Have a rest!"));
}

CMAssistant::~CMAssistant()
{
    foreach (CTimedReminder* reminder, m_timedReminders) {
        reminder->stop();
        reminder->deleteLater();
    }

//    QThread thread;
//    thread.msleep(500);
}

void CMAssistant::showTrayIcon()
{
    m_trayIcon.show();
}
