#include "dcmotor.h"

DCMotor::DCMotor(int pinMotorA, int pinMotorB, int pinMotorE)
{
    m_pinMotorA=pinMotorA;
    m_pinMotorB=pinMotorB;
    m_pinMotorE=pinMotorE;
    m_pwm=40;
}

bool DCMotor::initPins()
{
    bool bCondA = m_pinMotorA <= 30 && !(m_pinMotorA < 0);
    bool bCondB = m_pinMotorB <= 30 && !(m_pinMotorB < 0);
    bool bCondE = m_pinMotorE <= 30 && !(m_pinMotorE < 0);
    if(bCondA && bCondB && bCondE)
    {
       /* pinMode(m_pinMotorA,OUTPUT);
        pinMode(m_pinMotorB,OUTPUT);
        pinMode(m_pinMotorE,PWM_OUTPUT);
        softPwmCreate(m_pinMotorE,nMinPWM,nMaxPWM);*/
        return true;
    }
    else return false;
}

void DCMotor::forward()
{
    /*digitalWrite(m_pinMotorA,0);
    digitalWrite(m_pinMotorB,1);
    softPwmWrite(m_pinMotorE,m_pwm);*/
}

void DCMotor::backward()
{
   /* digitalWrite(m_pinMotorA,1);
    digitalWrite(m_pinMotorB,0);
    softPwmWrite(m_pinMotorE,m_pwm);*/
}

void DCMotor::stop()
{
   // softPwmWrite(m_pinMotorE,0);
}

int DCMotor::setPWM(const int pwm)
{
  if(pwm < nMinPWM)
    m_pwm = nMinPWM;
  else if(pwm > nMaxPWM)
    m_pwm = nMaxPWM;
  else
    m_pwm = pwm;
  return m_pwm;
}

int DCMotor::getPWM()
{
    return m_pwm;
}
