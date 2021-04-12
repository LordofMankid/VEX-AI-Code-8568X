#pragma once
#include "vex.h"
 
using namespace vex;
 
polarCoord rectToPol(double x, double y);
 
polarCoord rectToPol(rectCoord rect);
 
rectCoord polToRect(double radius, double theta);
 
double calcDistance(rectCoord rect);
 
double calcDistance(double x, double y);
 
double calcDistance(polarCoord polar);
 
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
};
