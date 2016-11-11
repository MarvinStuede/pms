//! \author Christopher Lange,
//!         Marvin Stuede,
//!         Gruppe 5
//! \date   November, 2016
//! \brief  Initializes a DC Motor connected with H bridge via GPIO, executes basic motion commands.

#ifndef DCMOTOR_H
#define DCMOTOR_H
#include <wiringPi.h>
#include <softPwm.h>

class DCMotor
{
public:

  //! \brief Constructor
  //!
  //! \param [in] nPinMotorA GPIO Pin A to connect with H bridge for rotation direction
  //! \param [in] nPinMotorB GPIO Pin B to connect with H bridge for rotation direction
  //! \param [in] nPinMotorE GPIO Pin E to connect PWM input of H bridge
  DCMotor(int nPinMotorA, int nPinMotorB, int nPinMotorE);

  //! \brief Initialize GPIO Pins.
  //!
  //! Initializes the GPIO Pins set at Constructor call. The Function checks whether all values are greater
  //! than 0 and smaller than 29.
  //! \return true if all Pin numbers are valid, false if at least one is not
  bool initPins();

  //! \brief Rotate Motor forwards.
  //!
  //! Rotate Motor with speed set by DCMotor::setPWM. Sets Pin A low, Pin B high.
  void forward();

  //! \brief Rotate Motor backwards.
  //!
  //! Rotate Motor with speed set by DCMotor::setPWM. Sets Pin A high, Pin B low.
  void backward();

  //! \brief Stop Motor.
  //!
  //! Stop motor by setting PWM to minimal value.
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
