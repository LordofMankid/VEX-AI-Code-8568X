//#include "chassis.h"
#include "math.h"
using namespace vex;

extern brain Brain;

extern motor intakeLeft;
extern motor intakeRight;
extern controller Controller;
extern motor sorter;
extern motor transport;
extern optical ColorSorter;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);