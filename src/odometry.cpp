#include "vex.h"

const double TR_TICK_INCH = TICKS_TRACKING_REV/(2.5*PI);
const double TR_INCH_TICK = 2.5*PI/TICKS_TRACKING_REV;

  void odometry::resetPosition(){

  }
  
  void odometry::updatePosition(){
      
    //step 1 - update tracking wheels, convert to inches
    positionL = trackingLeft.rotation(degrees)*TR_TICK_INCH;
    positionR = trackingRight.rotation(degrees)*TR_TICK_INCH;
    positionH = trackingX.rotation(degrees)*TR_TICK_INCH;

    //step 2 - find change in tracking wheels since last cycle
    deltaL = positionL - lastPositionL;
    deltaR = positionR - lastPositionR;
    deltaX = positionH - lastpositionH;

    //step 3 - update lastPosition variables for the next cycle
    lastPositionL = positionL;
    lastPositionR = positionR;
    lastpositionH = positionH;

    //step 4 - find total change since the last reset
    deltaLr = positionL - initL;
    deltaRr = positionR - initR;

    //step 5 = find the change in angle using the cool equation
    angle = initAngle + (deltaLr-deltaRr)/(RIGHTWHEELDISTANCE+LEFTWHEELDISTANCE);

    //step 6 - find the change in angle since the last cycle
    deltaAngle = angle - lastAngle;
    deltaXtest = deltaX - XWHEELDISTANCE*deltaAngle; //accounts for the tracking wheel's turning distance using the arclength formulra

    //step 7 - Record the XY coordinate changes of the robot - if change in angle = 0, then it's just the straight up XY distance
    if(deltaAngle == 0){ //also makes it so you don't divide by 0 lol
      deltaPositionX = deltaX;
      deltaPositionY = deltaR;
    }
    //step 8 - Record the XY coordinate changes of the robot accounting for a change in orientation, then it "turns" the XY coordinates
    else{
      deltaPositionX = (2*sin(deltaAngle/2))*(deltaX/deltaAngle + XWHEELDISTANCE);
      deltaPositionY = (2*sin(deltaAngle/2))*(deltaR/deltaAngle + RIGHTWHEELDISTANCE);
    }

    //step 9 - Calculate
    angleM = angle + deltaAngle/2;;



    //step 10 - Adjust XY coordinates to regular coordinate by changing to polar coordinates, adding angleM, and changing back
      //Converts to polar coodinates
    theta = atan2f(deltaPositionY, deltaPositionX); //finds the angle
    radius = sqrt(deltaPositionX*deltaPositionX + deltaPositionY*deltaPositionY); //finds the radius
      //Changes the angle to the regular coordinate system (this adjusts the X/Y coordinate tilting thing)
    theta = theta - angleM;
      //Converts back from polar coordinates

    deltaPositionX = radius*cos(theta);
    deltaPositionY = radius*sin(theta);

      //Converts angle to between 0 and 2pi (it's in radians right now)
    /*angle += PI;
    while(angle < 0) {
      angle +=2*PI;
    }
    angle = modulo(angle, 2*PI);
    angle -= PI;*/

    //step 11 - Update final positions
    lastAngle = angle;

  //  angle = angle*180.0/PI; //converts to degrees
    if(fabs(deltaPositionX) > 10)
      deltaPositionX = 0;
    if(fabs(deltaPositionY) > 10)
      deltaPositionY = 0;

    

    currPosition.xPosition = currPosition.xPosition + deltaPositionX;
    currPosition.yPosition = currPosition.yPosition + deltaPositionY;
    currPosition.angle = angle; //orientation in radians


  }

  double modulo(double a, double b);
  
  double odometry::getYposition(){

    return currPosition.yPosition;
  }
  
  double odometry::getXposition(){
    return currPosition.xPosition;
  }

  double getAngleRad(){
    return 2.0;
  }
  
  double getAngleDeg();
