#pragma once
#include "calculate.h"
using namespace vex;

extern int yPowerDrive;
extern int xPowerDrive;
extern int rPowerDrive;

/*
Declares a four-motor chassis class.

*Parameters: FrontLeftMotor, FrontRightMotor, BackLeftMotor, BackRightMotor, type vex::motor



*/
class chassis
{
  private:
  motor FrontLeft = motor(PORT1);
  motor FrontRight = motor(PORT2);
  motor BackLeft = motor(PORT3);
  motor BackRight = motor(PORT4);

  int yPowerDrive;
  int xPowerDrive;
  int rPowerDrive;

  static double kP;
  static double kI;
  static double kD;
  
  public:
  chassis() {};
  chassis(motor FrontLeftMotor, motor FrontRightMotor, motor BackLeftMotor, motor BackRightMotor);

  void setChassisMotors(motor FrontLeftMotor, motor FrontRightMotor, motor BackLeftMotor, motor BackRightMotor);
  void setHoloDrive(int yPower, int xPower, int rPower);
  void setTankDrive(int yPower, int rPower);
  void setDriveMotors();
  void move(double target);
  void setPID(double kP, double kI, double kD);
  double get_kP();
  double get_kI();
  double get_kD();
 // kPID get_kPID();
};


void setDrive(int yPower, int xPower, int rPower);

void setDriveMotors();

extern chassis xChassis;

class newChassis
{
  private:
  chassis chassis;
  
  public:
  newChassis(){ };
  
};
