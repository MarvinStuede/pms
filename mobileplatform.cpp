#include "mobileplatform.h"

MobilePlatform::MobilePlatform(QObject *parent) :
    QObject(parent)
  ,MotorLeft(nMotorLeftPin1,nMotorLeftPin2,nMotorLeftPinPWM)
  ,MotorRight(nMotorRightPin1,nMotorRightPin2,nMotorRightPinPWM)
{

}
void MobilePlatform::initializeGPIO()
{

  /*if(wiringPiSetup() == -1){
      emit logMsg("GPIO Pin Setup failed");
      emit logMsg("Motors not initialized");
      return;
  }*/

  if(MotorLeft.initPins())
      emit logMsg("Left Motor initialized");
  else
      emit logMsg("Left Motor not initialized");

  if(MotorRight.initPins())
      emit logMsg("Right Motor initialized");
  else
      emit logMsg("Right Motor not initialized");
}

void MobilePlatform::moveForward()
{
  MotorLeft.forward();
  MotorRight.forward();
  emit logMsg("Moving Forward");
}

void MobilePlatform::moveBackward()
{
  MotorLeft.backward();
  MotorRight.backward();
  emit logMsg("Moving Backward");
}

void MobilePlatform::turnLeft()
{
  MotorLeft.stop();
  MotorRight.forward();
  emit logMsg("Turning left");
}

void MobilePlatform::turnRight()
{
  MotorLeft.forward();
  MotorRight.stop();
  emit logMsg("Turning right");
}

void MobilePlatform::stopMotion()
{
  MotorLeft.stop();
  MotorRight.stop();
  emit logMsg("Stopping");
}

int MobilePlatform::setPWM(int spnbxValue)
{
  int nLeft = MotorLeft.setPWM(spnbxValue);
  int nRight = MotorRight.setPWM(spnbxValue);

  std::stringstream ssOut;
  ssOut << "Set PWM: Left Motor: "<< nLeft << ", Right Motor: " << nRight;
  emit logMsg(QString::fromStdString(ssOut.str()));
  return nLeft;
}
