#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */


motor FrontLeft = motor(PORT2);
motor FrontRight = motor(PORT3);
motor BackLeft = motor(PORT10);
motor BackRight = motor(PORT7);

void vexcodeInit(void) {
  // Nothing to initialize
//  chassis xChassis;
}