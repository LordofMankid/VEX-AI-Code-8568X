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
  sorterBot.setVelocity(pwr, percent);
  sorterTop.setVelocity(pwr, percent);
  sorterBot.spin(forward);
  sorterTop.spin(forward);
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
    sorterTop.stop();
    sorterBot.stop();
  }


}

void colorSort(bool redSide)
{
  int reverse = 1;
  if (redSide == false)
  {
    reverse = - reverse;
  }
  if (ColorSorter.color() == red)
  {
    setSorterSpeed(100 * reverse);
  } else if (ColorSorter.color() == blue)
  {
    setSorterSpeed(-100 * reverse);
  } else {
    sorterTop.stop();
    sorterBot.stop();
  }
}

void score(bool redSide)
{
 colorSort(redSide);
  setTransportSpeed(100);
  if (ColorSorter.isNearObject() == true)
  {
    Brain.resetTimer(); 
  }
  if (Brain.timer(sec) >= 0.5)
  {
    transport.stop();
  }
}

void setScoreBrake(){
  intakeLeft.setBrake(brakeType::brake);
  intakeRight.setBrake(brakeType::brake);
  sorterTop.setBrake(brakeType::brake);
  sorterBot.setBrake(brakeType::brake);
  transport.setBrake(brakeType::brake);

}
