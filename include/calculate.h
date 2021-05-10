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
  double PID(double targ);
  double findDistance(rectCoord initPosition, rectCoord finalPosition);
  rectCoord vectorSummation(rectCoord v1, rectCoord v2);
  rectCoord vectorSummation(rectCoord v1, position v2);
  int compareValues(double a, double b);
  double radianModulate(double theta);
  
  //double PID(rectCoord targetPosition, position currPosition);
};