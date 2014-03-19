#ifndef MW_TRAYICON_H
#define MW_TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>

class CMainWindow;
class CTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit CTrayIcon(CMainWindow& window, QObject *parent = 0);
    ~CTrayIcon();
signals:

public slots:
    void showMainWindow();
    void on_tryaIcon_clicked(QSystemTrayIcon::ActivationReason reasion);
    void on_message_remind(QString msg);

private:
    void createContextMenu();

private:
    QMenu m_menu;
    CMainWindow& m_mainWindow;

};

#endif // MW_TRAYICON_H
