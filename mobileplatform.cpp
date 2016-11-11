#include "mobileplatform.h"

MobilePlatform::MobilePlatform(QObject *parent) :
    QObject(parent)
  ,m_MotorLeft(s_nMotorLeftPin1,s_nMotorLeftPin2,s_nMotorLeftPinPWM)
  ,m_MotorRight(s_nMotorRightPin1,s_nMotorRightPin2,s_nMotorRightPinPWM)
  ,m_LineSensorLeft(s_nLineSensorLeft)
  ,m_LineSensorRight(s_nLineSensorRight)
{
  m_bFollowing = false;
  m_nLastCmdSpeedLeft = 40;
  m_nLastCmdSpeedRight = 40;
  m_fReductionFactor = 0.3;

}
void MobilePlatform::initializeGPIO()
{

  if(wiringPiSetup() == -1)
  {
      emit sgnLogMsg("GPIO Pin Setup failed");
      emit sgnLogMsg("Motors and Sensors not initialized");
      return;
  }

  if(m_MotorLeft.initPins())
      emit sgnLogMsg("Left motor initialized");
  else
      emit sgnLogMsg("[ERROR]: Left motor not initialized");

  if(m_MotorRight.initPins())
      emit sgnLogMsg("Right motor initialized");
  else
      emit sgnLogMsg("[ERROR]: Right motor not initialized");

  if(m_LineSensorLeft.initPin())
      emit sgnLogMsg("Left line sensor initialized");
  else
      emit sgnLogMsg("[ERROR]: Left line sensor not initialized");

  if(m_LineSensorRight.initPin())
      emit sgnLogMsg("Right line sensor initialized");
  else
      emit sgnLogMsg("[ERROR]: Right line sensor not initialized");
}

void MobilePlatform::setReductionFactor(double dbFactor)
{
    m_fReductionFactor = dbFactor;
    std::stringstream ssOut;
    ssOut << "Reduce speed of slower motor for line following to "<< m_fReductionFactor * 100 << "%";
    emit sgnLogMsg(QString::fromStdString(ssOut.str()));
}

void MobilePlatform::moveForward()
{
  m_MotorLeft.forward();
  m_MotorRight.forward();
  emit sgnLogMsg("Move Command: Forward");
}

void MobilePlatform::moveBackward()
{
  m_MotorLeft.backward();
  m_MotorRight.backward();
  emit sgnLogMsg("Move Command: Backward");
}

void MobilePlatform::turnLeft()
{
  m_MotorLeft.stop();
  m_MotorRight.forward();
  emit sgnLogMsg("Move Command: Left");
}

void MobilePlatform::turnRight()
{
  m_MotorLeft.forward();
  m_MotorRight.stop();
  emit sgnLogMsg("Move Command: Right");
}

void MobilePlatform::stopMotion()
{
  m_MotorLeft.stop();
  m_MotorRight.stop();
  m_bFollowing = false;
  emit sgnLogMsg("Move Command: Stop");
}

void MobilePlatform::startLineFollowing()
{//Call Function to start line following, only if it is not started already
  if(!m_bFollowing)
  {
    m_bFollowing = true;
    emit sgnFollowing(true);
    followLine();
  }
  else emit sgnFollowing(false);
}

void MobilePlatform::setPWM(int nSpnbxValue)
{
  m_nLastCmdSpeedLeft = m_MotorLeft.setPWM(nSpnbxValue);
  m_nLastCmdSpeedRight = m_MotorRight.setPWM(nSpnbxValue);

  std::stringstream ssOut;
  ssOut << "Set PWM: Left Motor: "<< m_nLastCmdSpeedLeft << ", Right Motor: " << m_nLastCmdSpeedRight;
  emit sgnLogMsg(QString::fromStdString(ssOut.str()));
}

void MobilePlatform::followLine()
{
  int nSpeedLeft;
  int nSpeedRight;
  int nOldCase = 0;

  while(m_bFollowing)
  {
    bool bLeftSensorOnLine = m_LineSensorLeft.isOverBlack();
    bool bRightSensorOnLine = m_LineSensorRight.isOverBlack();

    if (!bLeftSensorOnLine && bRightSensorOnLine)
    {
        nSpeedLeft = m_nLastCmdSpeedLeft;
        nSpeedRight = m_nLastCmdSpeedRight;

        if(nOldCase != 1)
            emit sgnLogMsg("Line follower: Going straight");
        nOldCase = 1;
    }
    else if (bLeftSensorOnLine)
    {
        nSpeedLeft = m_nLastCmdSpeedLeft *  m_fReductionFactor;
        nSpeedRight = m_nLastCmdSpeedRight;

        if(nOldCase != 2)
            emit sgnLogMsg("Line follower: Going left");
        nOldCase = 2;
    }
    else if (!bRightSensorOnLine)
    {
        nSpeedLeft = m_nLastCmdSpeedLeft;
        nSpeedRight = m_nLastCmdSpeedRight *  m_fReductionFactor;

        if(nOldCase != 3)
            emit sgnLogMsg("Line follower: Going right");
        nOldCase = 3;
    }
    else
    {
        nSpeedLeft = 0;
        nSpeedRight = 0;
        emit sgnLogMsg("[ERROR]: Line sensor output not catched");
    }

    m_MotorLeft.setPWM(nSpeedLeft);
    m_MotorRight.setPWM(nSpeedRight);
    m_MotorLeft.forward();
    m_MotorRight.forward();

    qApp->processEvents();
  }

  m_MotorLeft.setPWM(m_nLastCmdSpeedLeft);
  m_MotorRight.setPWM(m_nLastCmdSpeedRight);
}
