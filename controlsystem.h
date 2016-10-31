#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <QObject>
#include "mobileplatform.h"
#include "mainwindow.h"

class ControlSystem : public QObject
{
    Q_OBJECT
public:
    explicit ControlSystem(QObject *parent = 0);
    ~ControlSystem();
private:
   MobilePlatform *m_pMobilePlatform;
   MainWindow *m_pMainWindow;

public slots:

};

#endif // CONTROLSYSTEM_H
