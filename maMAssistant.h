#ifndef MAMASSISTANT_H
#define MAMASSISTANT_H

#include <QObject>

class CTrayIcon;
class CMainwindow;
class CMAssistant : public QObject
{
    Q_OBJECT
public:
    explicit CMAssistant(QObject *parent = 0);

signals:

public slots:

private:
//    CTrayIcon& m_trayIcon;
//    CMainwindow& m_mainWindow;
};

#endif // MAMASSISTANT_H
