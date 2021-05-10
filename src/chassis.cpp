#include "vex.h"

  chassis::chassis(motor FrontLeftMotor, motor FrontRightMotor, motor BackLeftMotor, motor BackRightMotor){
      FrontLeft = FrontLeftMotor;
      FrontRight = FrontRightMotor;
      BackLeft = BackLeftMotor;
      BackRight = BackRightMotor;


  }

  void chassis::setHoloDrive(int yPower, int xPower, int rPower){
      FrontLeft.setVelocity(yPower + xPower + rPower, velocityUnits::pct);
      FrontRight.setVelocity(yPower - xPower - rPower, velocityUnits::pct);
      BackLeft.setVelocity(yPower - xPower + rPower, velocityUnits::pct);
      BackRight.setVelocity(yPower + xPower - rPower, velocityUnits::pct);

      FrontLeft.spin(forward);
      FrontRight.spin(forward);
      BackLeft.spin(forward);
      BackRight.spin(forward);
  }
  void chassis::setTankDrive(int yPower, int rPower){


  }
  void chassis::setDriveMotors(){

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
  void move(double target);
  void setPID(double kP, double kI, double kD);
  void chassis::setChassisBrake()
  {
    FrontLeft.setBrake(brakeType::brake);
    FrontRight.setBrake(brakeType::brake);
    BackLeft.setBrake(brakeType::brake);
    BackRight.setBrake(brakeType::brake);
  }

  double get_kP();
  double get_kI();
  double get_kD();
