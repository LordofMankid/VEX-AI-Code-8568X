#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */

motor intakeLeft = motor(PORT5, ratio18_1, false);
motor intakeRight = motor(PORT6, ratio18_1, true);
motor sorterBot = motor(PORT8, ratio18_1, true);
motor sorterTop = motor(PORT1, ratio6_1, true);
motor transport = motor(PORT9, ratio18_1, false);

optical ColorSorter = optical(PORT14);


controller Controller;

void vexcodeInit(void) {
  // Nothing to initialize
//  chassis xChassis;
}