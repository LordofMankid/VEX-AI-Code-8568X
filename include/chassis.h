#pragma once
using namespace vex;

extern int yPowerDrive;
extern int xPowerDrive;
extern int rPowerDrive;


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
};


void setDrive(int yPower, int xPower, int rPower);

void setDriveMotors();

class newChassis
{
  private:
  chassis chassis;
  
  public:
  newChassis(){ };
  
};