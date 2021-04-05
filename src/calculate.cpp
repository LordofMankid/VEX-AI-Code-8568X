#include "vex.h"


double calculate::PID(double targetPosition, double encoderValue, kPID kPID){
  
  int voltage;

  //sets error

  error = targetPosition - encoderValue;

  //increases error based on time taken to reach target - if resistance is encountered then integral will increase

  integral = integral + error;

  //resets integral if place is reached

  if(error == 0)

    integral = 0;

  //reset integral if it becomes super big

  if(fabs(error) >= integralMax)

    integral = 0;

  derivative = prevError - error; //finds derivative of errors

  prevError = error; //updates prevError

  //set voltage to equal the error

  voltage = (error*kPID.kP) + (integral*kPID.kI) + (derivative*kPID.kD);

  if(voltage > 100)

    voltage = 100;

  if(voltage < -100)

    voltage = -100;

  return voltage;

}