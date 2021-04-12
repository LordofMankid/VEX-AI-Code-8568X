#include "vex.h"
 
 
double calculate::PID(double targetPosition, double encoderValue, kPID kPID){
  int voltage;
 
 //sets error
 
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
 
 //set voltage to equal the error
 
 voltage = (error*kPID.kP) + (integral*kPID.kI) + (derivative*kPID.kD);
 
 if(voltage > 100)
 
   voltage = 100;
 
 if(voltage < -100)
 
   voltage = -100;
 
 return voltage;
 
}
 
polarCoord calculate::rectToPol(double x, double y)
{
 polarCoord polar;
 double radius;
 radius = sqrt(pow(x,2)+ pow(y,2));
 polar.radius = radius;
 double theta;
 theta = atan(y / x);
 polar.angle = theta;
 return polar;
}
 
polarCoord calculate::rectToPol(rectCoord rect)
{
 return rectToPol(rect.x, rect.y);
}
 
rectCoord calculate::polToRect(double radius, double theta)
{
 rectCoord rect;
 double x;
 x = radius * cos(theta);
 rect.x = x;
 double y;
 y = radius * sin(theta);
 rect.y = y;
 return rect;
}

rectCoord calculate::polToRect(polarCoord polar)
{
  return polToRect(polar.radius, polar.angle);
}
 
double calculate::calcDistance(double x, double y)
{
 double distance;
 distance = sqrt(pow(x,2)+pow(y,2));
 return distance;
}
 
double calculate::calcDistance(rectCoord rect)
{
 return calcDistance(rect.x, rect.y);
}

double calculate::calcDistance(polarCoord polar)
{
 rectCoord rect;
 rect = polToRect(polar);
 return calcDistance(rect);
}