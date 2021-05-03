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

int yPowerDrive;
int xPowerDrive;
int rPowerDrive;

void setDrive(int yPower, int xPower, int rPower){
  
  topLeftMotor.setVelocity(yPower + xPower + rPower, velocityUnits::pct);
  topRightMotor.setVelocity(yPower - xPower - rPower, velocityUnits::pct);
  botLeftMotor.setVelocity(yPower - xPower + rPower, velocityUnits::pct);
  botRightMotor.setVelocity(yPower + xPower - rPower, velocityUnits::pct);
  
  topLeftMotor.spin(directionType::fwd);
  topRightMotor.spin(directionType::fwd);
  botLeftMotor.spin(directionType::fwd);
  botRightMotor.spin(directionType::fwd);

  if(yPower == 0 && xPower == 0 && rPower == 0)
  {
    topLeftMotor.stop();
    topRightMotor.stop();
    botLeftMotor.stop();
    botRightMotor.stop();
    
  }


}



void setDriveMotors()
{
  if(abs(Controller.Axis2.value() < 5))
  {
   yPowerDrive = 0;
  } else {
    yPowerDrive = Controller.Axis2.value();
  }
  
  if(abs(Controller.Axis4.value() < 5))
  {
    xPowerDrive = 0;
  } else {
     xPowerDrive = Controller.Axis4.value();
  }
  
  if(abs(Controller.Axis3.value() < 5))
  {
    xPowerDrive = 0;
  } else {
     xPowerDrive = Controller.Axis3.value();
  }
 
  setDrive(yPowerDrive, xPowerDrive, rPowerDrive);
}


frontRightMotor.setVelocity(yPower - rPower, velocityUnits::pct);
backRightMotor.setVelocity(yPower - rPower, velocityUnits::pct);
frontLeftMotor.setVelocity(yPower + rPower, velocityUnits::pct);
backLeftMotor.setVelocity(yPower + rPower, velocityUnits::pct);