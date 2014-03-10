#ifndef MW_TRAYICON_H
#define MW_TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>
#include "MA_MainWindow.h"

class MA_TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit MA_TrayIcon(MA_MainWindow& window, QObject *parent = 0);

signals:

public slots:
    void showMainWindow();
private:
    void createContextMenu();

private:
    QMenu m_menu;
    MA_MainWindow& m_mainWindow;
};

#endif // MW_TRAYICON_H
