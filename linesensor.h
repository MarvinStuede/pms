#ifndef LINESENSOR_H
#define LINESENSOR_H
//#include <wiringPi.h>

class LineSensor
{
public:
  LineSensor(int pinSensor);
  bool getStatus();
  bool initPin();
private:
  int m_nPin;
};

#endif // LINESENSOR_H
