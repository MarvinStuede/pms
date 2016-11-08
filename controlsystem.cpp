#include "controlsystem.h"

ControlSystem::ControlSystem(QObject *parent) :
    QObject(parent)
{
    m_pMobilePlatform = new MobilePlatform();
    m_pMainWindow = new MainWindow();

    QObject::connect(m_pMainWindow,SIGNAL(sgnForward()),m_pMobilePlatform,SLOT(moveForward()));
    QObject::connect(m_pMainWindow,SIGNAL(sgnBackward()),m_pMobilePlatform,SLOT(moveBackward()));
    QObject::connect(m_pMainWindow,SIGNAL(sgnRight()),m_pMobilePlatform,SLOT(turnRight()));
    QObject::connect(m_pMainWindow,SIGNAL(sgnLeft()),m_pMobilePlatform,SLOT(turnLeft()));
    QObject::connect(m_pMainWindow,SIGNAL(sgnStop()),m_pMobilePlatform,SLOT(stopMotion()));
    QObject::connect(m_pMainWindow,SIGNAL(spnboxSpeed_valueChanged(int)),m_pMobilePlatform,SLOT(setPWM(int)));
    QObject::connect(m_pMainWindow,SIGNAL(spnboxReduction_valueChanged(double)),m_pMobilePlatform,SLOT(setReductionFactor(double)));
    QObject::connect(m_pMainWindow,SIGNAL(sgnLine()),m_pMobilePlatform,SLOT(startLineFollowing()));
    QObject::connect(m_pMobilePlatform,SIGNAL(followingTriggered(bool)),m_pMainWindow,SLOT(logLineResponse(bool)));
    QObject::connect(m_pMobilePlatform,SIGNAL(logMsg(QString)),m_pMainWindow,SLOT(logMessage(QString)));

    m_pMobilePlatform->initializeGPIO();
    m_pMainWindow->emitStandardValues();
}

ControlSystem::~ControlSystem()
{
  delete m_pMobilePlatform;
  delete m_pMainWindow;
}
