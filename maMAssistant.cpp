#include "maMAssistant.h"
#include "maTimedReminder.h"
#include "maMainWindow.h"
#include "maTrayIcon.h"

const QString thought = QObject::tr("Those who can show the idea in my mind, are emerging from the heart.");

CMAssistant::CMAssistant(CTrayIcon& traIcon, CMainWindow& window, QObject* parent) :
    QObject(parent),
    m_trayIcon(traIcon),
    m_mainWindow(window)
{
    CTimedReminder* reminder = new CTimedReminder(this);
    connect(reminder, SIGNAL(timeToRemid(QString)), &m_trayIcon, SLOT(on_message_remind(QString)));
    m_timedReminders.append(reminder);
    reminder->startReminder(20 * 60, 20, thought);
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
