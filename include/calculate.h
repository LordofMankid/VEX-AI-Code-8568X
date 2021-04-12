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
  input: individual rectangular (x,y) coordinates
  converts the coordinates from rectangular to polar
  output: polar coordinate structure
  */
  polarCoord rectToPol(double x, double y);
  
  /*
  input: rectangular coordinate structure
  converts from rectangular to polar
  output: polar coordinate structure
  */
  polarCoord rectToPol(rectCoord rect);
 
  /*
  input: individual polar coordinates (r,Θ)
  converts the polar coordinates to rectangular
  output: rectangular coordinate structure
  */
  rectCoord polToRect(double radius, double theta);

  /*
  input: polar coordinate structure
  converts from polar to coordinate
  output: rectangular coordinate structure
  */
  rectCoord polToRect(polarCoord polar);
 
  /*
  input: individual rectangular coordinates (x,y)
  calculates the rectangular distance between them
  output: the distance (double)
  */
  double calcDistance(double x1, double y1, double x2, double y2);
 
  /*
  input: rectangular coordinate structure
  calcuates the rectangular distance between them
  output: the distance (double)
  */
  double calcDistance(rectCoord rect1, rectCoord rect2);

  double calcDistance(polarCoord polar1, polarCoord polar2);
};
