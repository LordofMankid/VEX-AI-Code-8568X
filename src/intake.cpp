#include "vex.h"

void setIntakeSpeed(int pwr) 
{
  intakeLeft.setVelocity(pwr, percent);
  intakeRight.setVelocity(pwr, percent);
  intakeLeft.spin(forward);
  intakeRight.spin(forward);
}

void setSorterSpeed(int pwr)
{
  sorter.setVelocity(pwr, percent);
  sorter.spin(forward);
}

void setTransportSpeed(int pwr)
{
  transport.setVelocity(pwr, percent);
  transport.spin(forward);
}
void setScore(){
  if (Controller.ButtonA.pressing()) {
    setIntakeSpeed(100);
  } else if (Controller.ButtonB.pressing()) {
    setIntakeSpeed(-100);
  } else {
    intakeLeft.stop();
    intakeRight.stop();
  }
  if (Controller.ButtonR2.pressing()) {
    setTransportSpeed(100);
  } else if (Controller.ButtonR1.pressing()) {
    setTransportSpeed(-100);
  } else {
    transport.stop();
  }
  if (Controller.ButtonL2.pressing()) {
    setSorterSpeed(100);
  } else if (Controller.ButtonL1.pressing()) {
    setSorterSpeed(-100);
  } else {
    sorter.stop();
  }


}


void setScoreBrake(){
  intakeLeft.setBrake(brakeType::brake);
  intakeRight.setBrake(brakeType::brake);
  sorter.setBrake(brakeType::brake);
  transport.setBrake(brakeType::brake);

}
