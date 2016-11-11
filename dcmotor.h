#ifndef DCMOTOR_H
#define DCMOTOR_H
#include <wiringPi.h>
#include <softPwm.h>

class DCMotor
{
public:
  DCMotor(int nPinMotorA, int nPinMotorB, int nPinMotorE);
  bool initPins();
  void forward();
  void backward();
  void stop();
  int setPWM(int nPWM);
  int getPWM();

private:
  int m_nPinMotorA;
  int m_nPinMotorB;
  int m_nPinMotorE;
  int m_nPWM;
  static const int s_nMaxPWM = 255;
  static const int s_nMinPWM = 0;
};

#endif // DCMOTOR_H
