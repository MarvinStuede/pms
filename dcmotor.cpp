#include "dcmotor.h"

DCMotor::DCMotor(int nPinMotorA, int nPinMotorB, int nPinMotorE)
{
    m_nPinMotorA=nPinMotorA;
    m_nPinMotorB=nPinMotorB;
    m_nPinMotorE=nPinMotorE;
    m_nPWM = 0;
}

bool DCMotor::initPins()
{
    bool bCondA = m_nPinMotorA <= 29 && !(m_nPinMotorA < 0);
    bool bCondB = m_nPinMotorB <= 29 && !(m_nPinMotorB < 0);
    bool bCondE = m_nPinMotorE <= 29 && !(m_nPinMotorE < 0);
    if(bCondA && bCondB && bCondE)
    {
        pinMode(m_nPinMotorA,OUTPUT);
        pinMode(m_nPinMotorB,OUTPUT);
        pinMode(m_nPinMotorE,PWM_OUTPUT);
        softPwmCreate(m_nPinMotorE,s_nMinPWM,s_nMaxPWM);
        return true;
    }
    else return false;
}

void DCMotor::forward()
{
    digitalWrite(m_nPinMotorA,0);
    digitalWrite(m_nPinMotorB,1);
    softPwmWrite(m_nPinMotorE,m_nPWM);
}

void DCMotor::backward()
{
    digitalWrite(m_nPinMotorA,1);
    digitalWrite(m_nPinMotorB,0);
    softPwmWrite(m_nPinMotorE,m_nPWM);
}

void DCMotor::stop()
{
    softPwmWrite(m_nPinMotorE,0);
}

int DCMotor::setPWM(int nPWM)
{
  if(nPWM < s_nMinPWM)
    m_nPWM = s_nMinPWM;
  else if(nPWM > s_nMaxPWM)
    m_nPWM = s_nMaxPWM;
  else
    m_nPWM = nPWM;
  return m_nPWM;
}

int DCMotor::getPWM()
{
    return m_nPWM;
}
