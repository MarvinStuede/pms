#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include <QObject>
#include <sstream>
#include <string>

class MobilePlatform : public QObject
{
    Q_OBJECT
public:
    explicit MobilePlatform(QObject *parent = 0);
    static const int nMotorLeft_Pin1 = 2;
    static const int nMotorLeft_Pin2 = 3;
    static const int nMotorLeft_PinPWM = 0;
    static const int nMotorRight_Pin1 = 10;
    static const int nMotorRight_Pin2 = 11;
    static const int nMotorRight_PinPWM = 6;
signals:
    void logMsg(const QString& msg);
public slots:
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stopMotion();
    int setPWM(int spnbxValue);

};

#endif // MOBILEPLATFORM_H
