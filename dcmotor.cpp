#include "dcmotor.h"

DCMotor::DCMotor(int pinMotorA, int pinMotorB, int pinMotorE)
{
    m_nPinMotorA=pinMotorA;
    m_nPinMotorB=pinMotorB;
    m_nPinMotorE=pinMotorE;
    m_nPWM=40;
}

bool DCMotor::initPins()
{
    bool bCondA = m_nPinMotorA <= 29 && !(m_nPinMotorA < 0);
    bool bCondB = m_nPinMotorB <= 29 && !(m_nPinMotorB < 0);
    bool bCondE = m_nPinMotorE <= 29 && !(m_nPinMotorE < 0);
    if(bCondA && bCondB && bCondE)
    {
       /* pinMode(m_nPinMotorA,OUTPUT);
        pinMode(m_nPinMotorB,OUTPUT);
        pinMode(m_nPinMotorE,PWM_OUTPUT);
        softPwmCreate(m_nPinMotorE,nMinPWM,nMaxPWM);*/
        return true;
    }
    else return false;
}

void DCMotor::forward()
{
    /*digitalWrite(m_nPinMotorA,0);
    digitalWrite(m_nPinMotorB,1);
    softPwmWrite(m_nPinMotorE,m_pwm);*/
}

void DCMotor::backward()
{
   /* digitalWrite(m_nPinMotorA,1);
    digitalWrite(m_nPinMotorB,0);
    softPwmWrite(m_nPinMotorE,m_pwm);*/
}

void DCMotor::stop()
{
   // softPwmWrite(m_nPinMotorE,0);
}

int DCMotor::setPWM(const int nPWM)
{
  if(nPWM < m_nMinPWM)
    m_nPWM = m_nMinPWM;
  else if(nPWM > m_nMaxPWM)
    m_nPWM = m_nMaxPWM;
  else
    m_nPWM = nPWM;
  return m_nPWM;
}

int DCMotor::getPWM()
{
    return m_nPWM;
}
