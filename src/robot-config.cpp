#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */

chassis xChassis = chassis(motor(PORT2), motor(PORT3), motor(PORT4), motor(PORT7));

encoder trackingLeft = encoder(Brain.ThreeWirePort.A);

motor intakeLeft = motor(PORT5, ratio18_1, false);
motor intakeRight = motor(PORT6, ratio18_1, true);

controller Controller;

void vexcodeInit(void) {
  // Nothing to initialize
  
}