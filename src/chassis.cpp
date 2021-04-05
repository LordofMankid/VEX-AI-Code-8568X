#include "vex.h"

using namespace vex;
/*

 Create a chassis class that: 
 Takes 4 motor objects in its constructor
 Configure them for X-Drive/Regular drive with a given input xPower(for xdrive), yPower, turnPower 
  *(something that looks like function chassis.setXdrivePower(input), chassis.setRegDrivePower(input))
  *a lot of functions will use this class to set the speed of the drive train so this is important
 Can set brake modes for the motors
 Provide basic auton functions that move to a given X, Y (for X-drive) and move a certain distance forward(for reg drive). Make a wheel constant for measuring  distance
  *more for practice so no stress here
 Update the header file accordingly as well
 *document so we can understand your thinking and give feedback

*/

//int yPowerDrive;
//int xPowerDrive;
//int rPowerDrive;

chassis xChassis = chassis(motor(PORT2), motor(PORT3), motor(PORT4), motor(PORT7));
chassis::chassis(motor FrontLeftMotor, motor FrontRightMotor, motor BackLeftMotor, motor BackRightMotor)
{
  FrontLeft = FrontLeftMotor;
  FrontRight = FrontRightMotor;
  BackLeft = BackRightMotor;
  BackRight = BackRightMotor;
}
void chassis::setHoloDrive(int yPower, int xPower, int rPower)
{  
  FrontLeft.setVelocity(yPower + xPower + rPower, velocityUnits::pct);
  FrontRight.setVelocity(yPower - xPower - rPower, velocityUnits::pct);
  BackLeft.setVelocity(yPower - xPower + rPower, velocityUnits::pct);
  BackRight.setVelocity(yPower + xPower - rPower, velocityUnits::pct);

  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  BackLeft.spin(forward);
  BackRight.spin(forward);

  
}
void chassis::setTankDrive(int yPower, int rPower)
{
  FrontLeft.setVelocity(yPower + rPower, percent);
  FrontRight.setVelocity(yPower - rPower, percent);
  BackLeft.setVelocity(yPower + rPower, percent);
  BackRight.setVelocity(yPower - rPower, percent);

  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  BackLeft.spin(forward);
  BackRight.spin(forward);
  
}
void chassis::setPID(double proportional, double integral, double derivative)
{
  kP = proportional;
  kI = integral;
  kD = derivative;
}

double chassis::get_kP()
{
  return kP;
}

double chassis::get_kI()
{
  return kI;
}

double chassis::get_kD()
{
  return kD;
}
/*
kPID chassis::get_kPID()
{

  return drivePID;
}*/
//void chassis::move(double target);
void chassis::setDriveMotors()
{
  if(abs(Controller.Axis3.value()) < 5)
  {
   yPowerDrive = 0;
  } else {
    yPowerDrive = Controller.Axis3.value();
  }
  
  if(abs(Controller.Axis4.value()) < 5)
  {
    xPowerDrive = 0;
  } else {
     xPowerDrive = Controller.Axis4.value();
  }
  
  if(abs(Controller.Axis1.value()) < 5)
  {
    rPowerDrive = 0;
  } else {
     rPowerDrive = Controller.Axis1.value();
  }
 
  setHoloDrive(yPowerDrive, xPowerDrive, rPowerDrive);
}

//--------------------------------------------



/*

void setDrive(int yPower, int xPower, int rPower){
  
  topLeftMotor.setVelocity(yPower + xPower + rPower, velocityUnits::pct);
  topRightMotor.setVelocity(yPower - xPower - rPower, velocityUnits::pct);
  botLeftMotor.setVelocity(yPower - xPower + rPower, velocityUnits::pct);
  botRightMotor.setVelocity(yPower + xPower - rPower, velocityUnits::pct);
  
  topLeftMotor.spin(forward);
  topRightMotor.spin(forward);
  botLeftMotor.spin(forward);
  botRightMotor.spin(forward);

  if(yPower == 0 && xPower == 0 && rPower == 0)
  {
    topLeftMotor.stop();
    topRightMotor.stop();
    botLeftMotor.stop();
    botRightMotor.stop();
    
  }


}

*/
