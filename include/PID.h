#pragma once
#include "vex.h"

using namespace vex;


class PID{
  private:
  double integral;
  double error;
  double derivative;
  int integralMax = 20;
  double prevError;

  public:
  PID(kPID constants);
  double calculateVoltage(double targetPosition, double encoderValue, kPID kPID);
  double findDistance(rectCoord initPosition, rectCoord finalPosition);
  
  //double PID(rectCoord targetPosition, position currPosition);
};