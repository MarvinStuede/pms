#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include <QObject>

class MobilePlatform : public QObject
{
    Q_OBJECT
public:
    explicit MobilePlatform(QObject *parent = 0);
    static const int nMotAPin1 = 2;
    static const int nMotAPin2 = 3;
    static const int nMotAPinPWM = 0;
    static const int nMotBPin1 = 10;
    static const int nMotBPin2 = 11;
    static const int nMotBPinPWM = 6;
signals:
    void logMsg(const QString& msg);
public slots:
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stopMotion();
    int setPWM();

};

#endif // MOBILEPLATFORM_H
