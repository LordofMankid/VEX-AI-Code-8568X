#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */

chassis xChassis = chassis(motor(PORT2), motor(PORT3), motor(PORT4), motor(PORT5));


motor topLeftMotor = motor(PORT1, ratio18_1, false);
motor botLeftMotor = motor(PORT2, ratio18_1, false);
motor topRightMotor = motor(PORT3, ratio18_1, false);
motor botRightMotor = motor(PORT4, ratio18_1, false);
motor intakeLeft = motor(PORT5, ratio18_1, false);
motor intakeRight = motor(PORT6, ratio18_1, true);

controller Controller;

void vexcodeInit(void) {
  // Nothing to initialize
  
}