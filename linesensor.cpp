#include "linesensor.h"

LineSensor::LineSensor(int pinSensor)
{
  m_nPin = pinSensor;
}

bool LineSensor::initPin()
{

  if(m_nPin <= 29 && !(m_nPin < 0))
  {

      //pinMode(m_nPin,INPUT);
      return true;
  }
  else return false;
}

bool LineSensor::getStatus()
{
  return 1 && 0;//digitalRead(m_nPin);
}

