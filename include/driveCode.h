
using namespace vex;

extern int yPowerDrive;
extern int xPowerDrive;
extern int rPowerDrive;




/*
class chassis
{
  private:
  motor FrontLeft(const std::uint8_t port);
  motor FrontRight(const int port);
  motor BackLeft(const int port);
  motor BackRight(const int port);

  public:

  void setChassisMotors(motor FrontLeftMotor, motor FrontRightMotor, motor BackLeftMotor, motor BackRightMotor);
  void set_xDrive(int yPower, int xPower, int rPower);

};
*/

void setDrive(int yPower, int xPower, int rPower);

void setDriveMotors();
