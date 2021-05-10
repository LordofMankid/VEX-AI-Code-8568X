#include "vex.h"
//units should be in inches

double calculate::findDistance(rectCoord initPosition, rectCoord finalPosition){
  double dist;
  dist = sqrt(pow(finalPosition.x - initPosition.x, 2) + pow(finalPosition.y - initPosition.y, 2));
  return dist;
}


double calculate::PID(double targetPosition, double encoderValue, kPID kPID){
  int force;
  error = targetPosition - encoderValue;
  
  //increases error based on time taken to reach target - if resistance is encountered then integral will increase
  integral = integral + error;
  //resets integral if place is reached
  if(error == 0)
    integral = 0;
  //reset integral if it becomes super big
  if(fabs(error) >= integralMax)
    integral = 0;
  derivative = prevError - error; //finds derivative of errors
  prevError = error; //updates prevError
  //set force to equal the error
  force = (error*kPID.kP) + (integral*kPID.kI) + (derivative*kPID.kD);
  if(force > 100)
    force = 100;
  if(force < -100)
    force = -100;

  return force;
 }

rectCoord calculate::vectorSummation(rectCoord v1, rectCoord v2){
  rectCoord newVector;
  newVector.y = v1.y + v2.y;
  newVector.x = v1.x + v2.x;

  return newVector;
}
rectCoord calculate::vectorSummation(rectCoord v1, position v2){
  rectCoord newVector;
  newVector.y = v1.y + v2.yPosition;
  newVector.x = v1.x + v2.xPosition;

  return newVector;
}
int calculate::compareValues(double a, double b){
  return (a < b ? 1:-1);
}

double modulate(double a, double b) {
  while (a>b) {
    a-=b;
  }
  return a;
}

double radianModulate(double theta){
   theta += PI;
  while(theta < 0) {
    theta +=2*PI;
  }
  theta = modulate(theta, 2*PI);
  theta -= PI;

  return theta;
}

