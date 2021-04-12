#pragma once
#include "vex.h"
 
using namespace vex;
 
class calculate{
 private:
 double integral;
 double error;
 double derivative;
 int integralMax = 20;
 double prevError;
 
 public:
 double PID(double targetPosition, double encoderValue, kPID kPID);
 double findDistance(rectCoord initPosition, rectCoord finalPosition);
  //double PID(rectCoord targetPosition, position currPosition);

  /*
  parameters: individual rectangular (x,y) coordinates
  converts the coordinates from rectangular to polar
  returns: polar coordinate structure
  */
  polarCoord rectToPol(double x, double y);
  
  /*
  parameters: rectangular coordinate structure
  converts from rectangular to polar
  returns: polar coordinate structure
  */
  polarCoord rectToPol(rectCoord rect);
 
  /*
  parameters: individual polar coordinates (r,Θ)
  converts the polar coordinates to rectangular
  returns: rectangular coordinate structure
  */
  rectCoord polToRect(double radius, double theta);

  /*
  parameters: polar coordinate structure
  converts from polar to coordinate
  returns: rectangular coordinate structure
  */
  rectCoord polToRect(polarCoord polar);
 
  /*
  parameters: 2 pairs of individual rectangular coordinates (x,y)
  calculates the rectangular distance between them
  returns: the distance (double)
  */
  double calcDistance(double x1, double y1, double x2, double y2);
 
  /*
  parameters: 2 rectangular coordinate structures
  calcuates the rectangular distance between them
  returns: the distance (double)
  */
  double calcDistance(rectCoord rect1, rectCoord rect2);

  /*
  parameters: 2 polar coordinate structures
  calculates the RECTANGULAR distance between them
  returns: the distance (double)
  */
  double calcDistance(polarCoord polar1, polarCoord polar2);
};
