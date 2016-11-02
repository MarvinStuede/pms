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
  int m_pinMotorA;
  int m_pinMotorB;
  int m_pinMotorE;
  int m_pwm;
  static const int nMaxPWM = 255;
  static const int nMinPWM = 0;
};

#endif // DCMOTOR_H
