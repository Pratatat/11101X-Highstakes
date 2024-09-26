#include "main.h"

void default_constants(){
  /*
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
   chassis.set_drive_constants(10, 0.5, 0,0, 0);
  chassis.set_heading_constants(2, .019, 0, 0, 0);
  chassis.set_turn_constants(10, 0.27, 0, 2.75, 0);
  chassis.set_swing_constants(10, 0.4, 0, 3.5, 0);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 300, 5000);
  chassis.set_turn_exit_conditions(2, 300, 3000);
  chassis.set_swing_exit_conditions(2, 300, 3000);
*/

  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(4, .4, 0, 1, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(12, .4, .018, 3, 15);
  chassis.set_swing_constants(12, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 25, 3000);
  chassis.set_turn_exit_conditions(4, 30, 1000);
  chassis.set_swing_exit_conditions(1.5, 50, 3000);
}
void new_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .39, .017, 3.3, 15);
  chassis.set_swing_constants(12, 0.25, .01, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 20, 3000);
  chassis.set_turn_exit_conditions(3, 15, 1000);
  chassis.set_swing_exit_conditions(3, 25, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 10;
  chassis.drive_kp = 0.9;
  chassis.drive_kd = 0.165;
  chassis.drive_settle_error = 3;
  chassis.turn_max_voltage = 10;
  chassis.turn_kp = 0.250;
  chassis.turn_ki = 0;
  chassis.turn_kd = 2;
  chassis.turn_settle_error = 3;
  chassis.turn_settle_time = 150;

}

void drive_test(){
  default_constants();
  chassis.drive_distance(6); 
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  default_constants();
  chassis.turn_to_angle(5, 8);
  chassis.turn_to_angle(30, 8);
  chassis.turn_to_angle(90, 8);
  chassis.turn_to_angle(225, 8);
  chassis.turn_to_angle(0, 8);
}

void swing_test(){
  default_constants();
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  default_constants();
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    pros::screen::erase();
    char *text = new char[16];
    std::sprintf(text, "X: %f", chassis.get_X_position());
    pros::screen::print(TEXT_MEDIUM, 0,50, text);
    delete [] text;
    text = new char[16];
    std::sprintf(text, "Y: %f", chassis.get_Y_position());
    pros::screen::print(TEXT_MEDIUM, 0, 70, text);
    delete [] text;
    text = new char[16];
    std::sprintf(text, "Heading: %f", chassis.get_absolute_heading());
    pros::screen::print(TEXT_MEDIUM, 0, 90, text);
    //delete [] text;
    //text = new char[16];
    //std::sprintf(text, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    //pros::screen::print(TEXT_MEDIUM, 0, 110, text);
    /*delete [] text;
    text = new char[16];
    std::sprintf(text, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    pros::screen::print(TEXT_MEDIUM, 0, 130, text);
    pros::delay(20);*/
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0,0,0);
  pros::delay(2000);
  chassis.turn_to_point(0, 24, 0, 10);
  pros::delay(25);
  chassis.turn_to_point(24, 0, 0, 10);
  pros::delay(25);
  chassis.turn_to_point(0, -24, 0, 10);
  pros::delay(25);
  chassis.turn_to_point(-24, 0, 0, 10);
  pros::delay(25);
  chassis.turn_to_point(0, 24, 0, 10);
  /*chassis.drive_to_point(0,24,10,0);
  pros::delay(100);
  chassis.turn_to_point(24,24,0,10);
  pros::delay(100);
  chassis.drive_to_point(24,24,10,0);
  pros::delay(100);
  chassis.turn_to_point(24,0,0,10);
  pros::delay(100);
  chassis.drive_to_point(24,0,10,0);
  pros::delay(100);
  chassis.turn_to_point(0,0,0,10);
  pros::delay(100);
  chassis.drive_to_point(0,0,10,0);
  pros::delay(100);
  chassis.turn_to_point(0,24,0,10);
  pros::delay(100);*/
}

void redSWP(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0,13.5,14,0);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(375);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-52,40);
  intake.move(600);
  chassis.drive_to_point(-49,37, 14, 0);
  intake.move(0);
  chassis.turn_to_point(-150,42);
  chassis.drive_to_point(-29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(175);
  chassis.drive_to_point(-40,37, 14, 0);
  chassis.turn_to_point(-45,55);
  chassis.drive_to_point(-45,51, 10, 0);
  pros::delay(400);
  chassis.drive_to_point(-40,40, 10, 0);
  chassis.turn_to_point(-52,56);
  chassis.drive_to_point(-50,51, 10, 0);
  pros::delay(400);
  chassis.drive_to_point(-29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(50,115);
  chassis.drive_distance(17);
}


void redRightQual(){
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(-24, -28);
  chassis.drive_to_point(-24, -28);
  pros::delay(1200);
  chassis.turn_to_point(0, -28);
  chassis.drive_to_point(0, -28);
  chassis.turn_to_point(24, -52);
  chassis.drive_to_point(8, -35);
  pneumatics.clench_v(0);
}

void redRightElim(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -27,14,0);
  pros::delay(200);
  chassis.turn_to_point(-30,24);
  pros::delay(200);
  chassis.drive_to_point(14.25,-40.25,14,0,1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(300);
  pneumatics.clench_v(0);
  chassis.turn_to_point(14, -20);
  chassis.drive_to_point(14, -30,14,0,1, 300, 600);
  pros::delay(150);
  intake.move(0);
  chassis.turn_to_point(-60,0);
  chassis.drive_to_point(24,-27,14,0,1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(250);
  chassis.turn_to_point(15,0);
  intake.move(-600);
  chassis.drive_to_point(15, -5,14,0);
  chassis.turn_to_point(0,4);
  pneumatics.doinker_v(1);
  chassis.drive_to_point(-5.5,4);
  pros::delay(250);
  intake.move(0);
  chassis.turn_to_point(-24,-60);
  /*
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(-24, -30);
  chassis.drive_to_point(-24, -30);
  pros::delay(1200);
  chassis.set_coordinates(0, 0, 0);
  intake.move(0);
  pros::delay(500);
  chassis.turn_to_point(-24, -16);
  pros::delay(200);
  chassis.drive_distance(-8);
  intake.move(-120);
  pros::delay(100);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(24, -2);
  chassis.drive_to_point(-6, 0);
  */
}



void redLeftElim(){
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,13.5);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(400);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-52,40);
  intake.move(600);
  chassis.drive_to_point(-49,37, 14, 0);
  pros::delay(0);
  intake.move(0);
  chassis.turn_to_point(-150,42);
  chassis.drive_to_point(-29,37, 14, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(-40,37, 14, 0);
  chassis.turn_to_point(-47,60);
  chassis.drive_to_point(-48,55, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(-44,51, 10, 0);
  chassis.turn_to_point(-50,56);
  chassis.drive_to_point(-52,55.5, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(-17.5,20, 14, 0,1, 400, 800);
}



void blueSWP(){
  //not mirrored
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,13.5);
  chassis.turn_to_point(100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-5, 15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(400);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0, 5, 9, 0,1, 400, 800);
  chassis.turn_to_point(52, 40);
  intake.move(600);
  chassis.drive_to_point(49, 37, 14, 0);
  pros::delay(0);
  intake.move(0);
  chassis.turn_to_point(150, 42);
  chassis.drive_to_point(29, 37, 14, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(40, 37, 14, 0);
  chassis.turn_to_point(47, 60);
  chassis.drive_to_point(48, 55, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(44, 51, 10, 0);
  chassis.turn_to_point(50, 56);
  chassis.drive_to_point(52, 55.5, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(42, 48, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-50, 115);
  chassis.drive_to_point(24, 60, 14, 0,1, 400, 800);
  
}


void blueLeftQual() {
  //not mirrored
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(24, -28);
  chassis.drive_to_point(24, -28);
  pros::delay(1200);
  chassis.turn_to_point(0, -28);
  chassis.drive_to_point(0, -28);
  chassis.turn_to_point(-24, -52);
  chassis.drive_to_point(-8, -35);
  pneumatics.clench_v(0);
}


void blueLeftElim() {
  //not mirrored
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(24, -28);
  chassis.drive_to_point(24, -28);
  pros::delay(1200);
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, -16);
  chassis.drive_to_point(12, 8);
  intake.move(-120);
  pros::delay(100);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(12, 0);
}

void blueRightElim(){
}

void skills() {
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, 24);
}
