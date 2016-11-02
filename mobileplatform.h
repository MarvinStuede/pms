#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include <QObject>
#include <sstream>
#include <string>
#include "dcmotor.h"

class MobilePlatform : public QObject
{
    Q_OBJECT
public:
    explicit MobilePlatform(QObject *parent = 0);
    static const int nMotorLeftPin1 = 2;
    static const int nMotorLeftPin2 = 3;
    static const int nMotorLeftPinPWM = 0;
    static const int nMotorRightPin1 = 10;
    static const int nMotorRightPin2 = 11;
    static const int nMotorRightPinPWM = 6;
signals:
    void logMsg(const QString& msg);
public slots:
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stopMotion();
    void initializeGPIO();
    int setPWM(int spnbxValue);
private:
    DCMotor MotorLeft;
    DCMotor MotorRight;

};

#endif // MOBILEPLATFORM_H
