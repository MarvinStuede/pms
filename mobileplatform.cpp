#include "mobileplatform.h"

MobilePlatform::MobilePlatform(QObject *parent) :
    QObject(parent)
{

}

void MobilePlatform::moveForward()
{

  emit logMsg("Moving Forward");
}

void MobilePlatform::moveBackward()
{
  emit logMsg("Moving Backward");
}

void MobilePlatform::turnLeft()
{
  emit logMsg("Turning left");
}

void MobilePlatform::turnRight()
{
  emit logMsg("Turning right");
}

void MobilePlatform::stopMotion()
{
  emit logMsg("Stopping");
}

int MobilePlatform::setPWM(int spnbxValue)
{

  return spnbxValue;
}
