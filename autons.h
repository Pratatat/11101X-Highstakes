#include "main.h"

class Drive;
class Intake;
class Pneumatics;

extern Drive chassis;
extern Intake intake;
extern Pneumatics pneumatics;

void default_constants();

void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();

void redSWP();
void redRightQual();
void redRightElim();
void redLeftElim();
void blueSWP();
void blueLeftQual();
void blueLeftElim();
void blueRightElim();
void skills();
void redFullArenaSWP();