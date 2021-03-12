#include "vex.h"


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

class chassis{ 
  private:
  motor FrontLeft, FrontRight, BackLeft, BackRight;
  
  public:
      
    void setChassisMotors(motor FrontLeftMotor, motor FrontRightMotor, motor BackLeftMotor, motor BackRightMotor){
      FrontLeft = FrontLeftMotor;
      FrontRight = FrontRightMotor;
      BackLeft = BackLeftMotor;
      BackRight = BackRightMotor;
    }
    void set_xDrive(int yPower, int xPower, int rPower){
      FrontLeft = yPower - xPower + rPower;

    }
  };


/*
class intake {
   motor FrontLeft;

   chassis();

   void setMotor1(motor A){
     FrontLeft = A;

   }
}; */