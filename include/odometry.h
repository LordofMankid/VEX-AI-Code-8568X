#pragma once
#include "vex.h"

using namespace vex;
#define TICKS_TRACKING_REV 360.0
#define PI 3.1415926535
extern brain Brain;

extern const double TR_TICK_INCH;
extern const double TR_INCH_TICK;


class odometry{
  private:
  encoder trackingLeft = encoder(Brain.ThreeWirePort.A);
  encoder trackingRight = encoder(Brain.ThreeWirePort.C);
  encoder trackingX = encoder(Brain.ThreeWirePort.E);
  ////
  double RIGHTWHEELDISTANCE = 1;
  double LEFTWHEELDISTANCE = 1;
  double XWHEELDISTANCE = 1;
  ////current positions of tracking wheels
  double positionL; //left wheel
  double positionR; //right wheel
  double positionH; //horizontal wheel

  ////change of position, in coordinates
  double deltaPositionX; //change of position along X axis
  double deltaPositionY; //change of position along Y axis

  ////initial tracking wheel values when resetting, normally should be 0
  double initL = 0.0;
  double initR = 0.0;
  double initX = 0.0;

  ////position of tracking wheel positions in the loop before
  double lastPositionL;
  double lastPositionR;
  double lastpositionH;

  ////change in position of the tracking wheels since the last cycle
  double deltaL; //change in position of the left tracking wheel since the last cycle
  double deltaR; //change in position of the right tracking wheel since the last cycle
  double deltaX; //change in position of the horizontal tracking wheel since the last cycle

  ////total change in position of the tracking wheel since the last reset of tracking wheels
  double deltaLr = 0.0;
  double deltaRr = 0.0;

  ////angle stuff
  double angle; //current calculated angle since last reset
  double lastAngle; //angle at last reset
  double deltaAngle; //change in angle since last cycle
  double angleM; //angle of the adjusted XY coordinate plane for translations

  ////polar coordinate stuff
  double theta = 0;
  double radius = 0;

  double deltaXtest;
  ////double
  double initAngle = 0.0;

  position currPosition;
  public:
  odometry(){};
  odometry(double RIGHTWHEELDISTANCE, double LEFTWHEELDISTANCE);
  //odometry(encoder trackingLeft, encoder trackingRight, encoder trackingX);
  
  void resetPosition();
  
  void updatePosition();

  double modulo(double a, double b);
  
  double getYposition();
  
  double getXposition();

  double getAngleRad();
  
  double getAngleDeg();

};

