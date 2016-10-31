#include "controlsystem.h"

ControlSystem::ControlSystem(QObject *parent) :
    QObject(parent)
{
    m_pMobilePlatform = new MobilePlatform();
    m_pMainWindow = new MainWindow();
    m_pMainWindow->show();

    QObject::connect(m_pMainWindow,SIGNAL(btnForward_clicked()),m_pMobilePlatform,SLOT(moveForward()));
    QObject::connect(m_pMainWindow,SIGNAL(btnBackward_clicked()),m_pMobilePlatform,SLOT(moveBackward()));
    QObject::connect(m_pMainWindow,SIGNAL(btnRight_clicked()),m_pMobilePlatform,SLOT(turnRight()));
    QObject::connect(m_pMainWindow,SIGNAL(btnLeft_clicked()),m_pMobilePlatform,SLOT(turnLeft()));
    QObject::connect(m_pMainWindow,SIGNAL(btnStop_clicked()),m_pMobilePlatform,SLOT(stopMotion()));
    QObject::connect(m_pMobilePlatform,SIGNAL(logMsg(QString)),m_pMainWindow,SLOT(log(QString)));
}

ControlSystem::~ControlSystem()
{
  delete m_pMobilePlatform;
  delete m_pMainWindow;
}
