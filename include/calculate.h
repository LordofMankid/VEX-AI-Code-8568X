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
 kPID pid_constants;
 public:

 double PID(double targetPosition, double encoderValue, kPID kPID);

 double findDistance(rectCoord initPosition, rectCoord finalPosition);
  //double PID(rectCoord targetPosition, position currPosition);


  polarCoord rectToPol(double x, double y);
 
  polarCoord rectToPol(rectCoord rect);
 
  rectCoord polToRect(double radius, double theta);

  rectCoord polToRect(polarCoord polar);
 
  double calcDistance(rectCoord rect);
 
  double calcDistance(double x, double y);
 
  double calcDistance(polarCoord polar);

  kPID setPID(double kP, double kI, double kD);

  double get_kP();

  double get_kI();

  double get_kD();
  
};
