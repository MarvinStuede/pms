#ifndef DCMOTOR_H
#define DCMOTOR_H
//#include <wiringPi.h>
//#include <softPwm.h>

class DCMotor
{
public:
  DCMotor(int pinMotorA, int pinMotorB, int pinMotorE);
  bool initPins();
  void forward();
  void backward();
  void stop();
  int setPWM(const int pwm);
  int getPWM();

private:
  int m_nPinMotorA;
  int m_nPinMotorB;
  int m_nPinMotorE;
  int m_nPWM;
  static const int m_nMaxPWM = 255;
  static const int m_nMinPWM = 0;
};

#endif // DCMOTOR_H
