#include "main.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
   chassis.set_drive_constants(10, 0.5, 0,0, 0);
  chassis.set_heading_constants(2, .019, 0, 0, 0);
  chassis.set_turn_constants(10, 0.27, 0, 2.75, 0);
  chassis.set_swing_constants(10, 0.4, 0, 3.5, 0);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 300, 5000);
  chassis.set_turn_exit_conditions(2, 300, 3000);
  chassis.set_swing_exit_conditions(2, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 10;
  chassis.drive_kp = 0.5;
  chassis.drive_kd = 0.3;
  chassis.drive_settle_error = 4;
  chassis.turn_max_voltage = 10;
  chassis.turn_kp = 0.27;
  chassis.turn_ki = 0;
  chassis.turn_kd = 1.7;
  chassis.turn_settle_error = 3;
  chassis.turn_settle_time = 200;
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
  chassis.set_coordinates(0,0,0);
  odom_constants();
  chassis.drive_to_point(0,24,10,2);
  chassis.turn_to_point(24,24,0,10);
  chassis.drive_to_point(24,24,10,2);
  chassis.turn_to_point(24,0,0,10);
  chassis.drive_to_point(24,0,10,2);
  chassis.turn_to_point(0,0,0,10);
  chassis.drive_to_point(0,0,10,2);
  chassis.turn_to_point(0,24,0,10);
}

void redSWP(){
  odom_constants();
  chassis.drive_distance(20);
  chassis.turn_to_angle(96);
  pneumatics.clench_v(1);
  chassis.drive_distance(-10);
  intake.move(500);
  pros::delay(200);
  pneumatics.clench_v(0);
  chassis.drive_distance(10);
  intake.move(-500);
  chassis.set_coordinates(24, 20, 0);
  chassis.turn_to_point(-24,50);
  chassis.drive_to_point(-12,38);
  intake.move(1000);
  chassis.drive_to_point(-24,50);
  pros::delay(300);
  intake.move(0);
  chassis.turn_to_point(-60,50);
  chassis.drive_to_point(0,48);
  pneumatics.clench_v(1);
  intake.move(800);
  pros::delay(200);
  chassis.drive_to_point(-24,50);
  chassis.turn_to_point(-28,72);
  chassis.drive_to_point(-28,65, 7, 0);
  pros::delay(800);
  chassis.drive_to_point(-24,30);
  pneumatics.clench_v(0);
  chassis.turn_to_point(12,60);
  chassis.drive_to_point(12,60);
}

void blueSWP(){
  odom_constants();
  chassis.set_coordinates(0,0, 0);
  chassis.drive_to_point(0,19);
  chassis.turn_to_point(-48,22);
  pneumatics.clench_v(1);
  chassis.drive_to_point(10, 19, 8, 0, 1, 200, 500);
  intake.move(600);
  pros::delay(600);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,19);
  chassis.set_coordinates(24, 20, 0);
  intake.move(-600);
  chassis.turn_to_point(50, 30);
  chassis.drive_to_point(50, 30);
  chassis.turn_to_point(72, 60);
  intake.move(450);
  chassis.drive_to_point(72, 60);
  pros::delay(200);
  intake.move(0);
  chassis.turn_to_point(200, 60);
  chassis.drive_to_point(44, 60);
  pneumatics.clench_v(1);
  pros::delay(300);
  intake.move(600);
  pros::delay(600);
  chassis.drive_to_point(70, 60);
  chassis.turn_to_point(70, 76);
  chassis.drive_to_point(70, 76);
  chassis.drive_distance(-10);
  chassis.turn_to_point(68,76);
  chassis.drive_to_point(68,76);
  pros::delay(800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(30,68);
  chassis.drive_to_point(30,68);
  /*
  chassis.set_coordinates(-24, 20, 0);
  chassis.turn_to_point(-40, 46);
  chassis.drive_to_point(-40, 46);
  intake.move(120);
  pros::delay(200);
  intake.move(0);
  chassis.turn_to_point(-72, 50);
  chassis.drive_to_point(-26, 50);
  pneumatics.clench_v(1);
  pros::delay(50);
  intake.move(120);
  chassis.turn_to_point(-8, 32, 0, 5);
  pros::delay(150);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-8, 32);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(11, 30);
  chassis.drive_to_point(11, 30);
  intake.move(120);
  chassis.turn_to_point(8, 0, 0, 6);
  chassis.drive_to_point(20, 50, 10, 8);
  pneumatics.clench_v(1);
  pros::delay(50);
  intake.move(120);
  chassis.turn_to_point(48, 12);
  chassis.drive_to_point(9, 58);
  intake.move(0);
  */
}

void redElim(){
  odom_constants();
  chassis.set_coordinates(24, 20, 0);
  chassis.drive_to_point(24, 38);
  pneumatics.clench_v(1);
  chassis.turn_to_point(40, 48);
  intake.move(120);
  chassis.drive_to_point(40, 48);
  pros::delay(200);
  chassis.turn_to_point(51, 64);
  chassis.drive_to_point(51, 64);
  chassis.turn_to_point(48, 54, 0, 6);
  chassis.drive_to_point(48, 54);
  chassis.turn_to_point(44, 64, 0, 6);
  chassis.drive_to_point(44, 64);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(9, 39, 0, 6);
  pneumatics.clench_v(0);
  chassis.drive_to_point(9, 39);
  intake.move(120);
  pros::delay(200);
  chassis.turn_to_point(2, 48, 0, 7);
  chassis.drive_to_point(-2, 10);
  intake.move(120);
}

void blueElim()
{
  odom_constants();
  chassis.set_coordinates(-24, 20, 0);
  chassis.drive_to_point(-24, 38);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-40, 48);
  intake.move(120);
  chassis.drive_to_point(-40, 48);
  pros::delay(200);
  chassis.turn_to_point(-51, 64);
  chassis.drive_to_point(-51, 64);
  chassis.turn_to_point(-48, 54, 0, 6);
  chassis.drive_to_point(-48, 54);
  chassis.turn_to_point(-44, 64, 0, 6);
  chassis.drive_to_point(-44, 64);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(-9, 39, 0, 6);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-9, 39);
  intake.move(120);
  pros::delay(200);
  chassis.turn_to_point(-2, 48, 0, 7);
  chassis.drive_to_point(2, 10);
  intake.move(120);
}
