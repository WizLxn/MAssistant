#include "maMAssistant.h"
#include "maTimedReminder.h"
#include "maMainWindow.h"
#include "maTrayIcon.h"

CMAssistant::CMAssistant(CTrayIcon &traIcon, CMainwindow &window, QObject *parent) :
    QObject(parent),
    m_trayIcon(traIcon),
    m_mainWindow(window)
{
    CTimedReminder* reminder = new CTimedReminder(this);
    //connect(reminder, SIGNAL(timeToRemid(QString)), &m_mainWindow, SLOT(on_message_remind(QString)));
    m_timedReminders.append(reminder);
}

CMAssistant::~CMAssistant()
{
    foreach (CTimedReminder* reminder, m_timedReminders) {
        reminder->quit();
        reminder->deleteLater();
    }
}
