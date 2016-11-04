#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include <QObject>
#include <sstream>
#include <string>
#include <QApplication>
#include "dcmotor.h"
#include "linesensor.h"

class MobilePlatform : public QObject
{
    Q_OBJECT
public:
    explicit MobilePlatform(QObject *parent = 0);
signals:
    void logMsg(const QString& msg);
    void followingTriggered(bool bTriggered);
public slots:
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stopMotion();
    void startLineFollowing();
    void initializeGPIO();
    int setPWM(int spnbxValue);
private:
    static const int s_nMotorLeftPin1    = 10;
    static const int s_nMotorLeftPin2    = 11;
    static const int s_nMotorLeftPinPWM  = 6;
    static const int s_nMotorRightPin1   = 2;
    static const int s_nMotorRightPin2   = 3;
    static const int s_nMotorRightPinPWM = 0;
    static const int s_nLineSensorRight  = 27;
    static const int s_nLineSensorLeft   = 28;
    int m_nLastCmdSpeedRight;
    int m_nLastCmdSpeedLeft;
    void followLine();

    bool bFollowing;
    DCMotor MotorLeft;
    DCMotor MotorRight;
    LineSensor LineSensorLeft;
    LineSensor LineSensorRight;
};

#endif // MOBILEPLATFORM_H
