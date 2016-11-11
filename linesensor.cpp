#include "linesensor.h"

LineSensor::LineSensor(int nPinSensor)
{
  m_nPin = nPinSensor;
}

bool LineSensor::initPin()
{

  if(m_nPin <= 29 && !(m_nPin < 0))
  {
      pinMode(m_nPin,INPUT);
      return true;
  }
  else return false;
}

bool LineSensor::isOverBlack()
{
  return 1 && digitalRead(m_nPin);
}

