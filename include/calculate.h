#pragma once
#include "vex.h"

using namespace vex;
 
typedef struct kPID{

  double kP;

  double kI;

  double kD;

} kPID;


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