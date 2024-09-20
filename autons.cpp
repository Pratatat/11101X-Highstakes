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
  chassis.drive_to_point(-42,48, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(50,115);
  chassis.drive_to_point(-24,60, 14, 0,1, 400, 800);
}


void redBasicQual(){
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
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
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
}



void redElim(){
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
  
  odom_constants();
  chassis.set_coordinates(0, 0, 180);
  chassis.drive_to_point(0, 27);
  pneumatics.clench_v(1);
  pros::delay(25);
  chassis.drive_to_point(0, 36);
  intake.move(127);
  chassis.set_coordinates(0, 0, 180);
  pros::delay(25);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(-26, 0);
  pros::delay(25);
  chassis.turn_to_point(-26, 24);
  chassis.drive_to_point(-26, 18);
  chassis.drive_to_point(-26, 14);
  chassis.turn_to_point(-22, 18);
  chassis.drive_to_point(-22, 18);
  chassis.drive_to_point(-26, 14);
  chassis.turn_to_point(12, -14);
  chassis.drive_to_point(12, -14);
  chassis.turn_to_point(24, -14);
  chassis.drive_to_point(24, -14);
  chassis.turn_to_point(72, 0);
  chassis.drive_to_point(72, 0);
  pneumatics.clench_v(0);
  chassis.turn_to_point(72, -24);
  chassis.drive_to_point(72, 14);
  pneumatics.clench_v(1);
  chassis.drive_to_point(72, 24);
  intake.move(0);




  /*chassis.set_coordinates(24, 20, 0);
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
  intake.move(120);*/
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


void blueBasicQual() {
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

void blueElim(){
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,8, 14, 0, 1, 200, 500);
  //intake.move(400);
  chassis.drive_to_point(0,18, 14, 0, 1, 200, 500);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_point(-60, 40, 0, 14, 1, 500, 700);
  chassis.set_coordinates(0,0,0);
  chassis.turn_to_point(24, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-24, 24, 14, 0, 1, 500, 700);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-48, 23, 0, 14, 1, 500, 700);
  intake.move(600);
  chassis.drive_to_point(-48, 23, 14, 0, 1, 500, 700);
  pros::delay(400);
  chassis.turn_to_point(12,0);
  intake.move(-600);
  chassis.drive_to_point(12,0, 14, 0, 1, 500, 700);
  chassis.turn_to_point(48,29);
  intake.move(600);
  chassis.drive_to_point(48,29, 14, 0, 1, 500, 700);
  pros::delay(500);
  chassis.turn_to_point(51,47);
  chassis.drive_to_point(51,47);
  pros::delay(400);
  chassis.drive_to_point(51,40);
  chassis.turn_to_point(47,49);
  chassis.drive_to_point(47,49);
  pros::delay(800);
  chassis.drive_to_point(44,40, 14, 0, 1, 200, 500);
  intake.move(0);*/
  /*
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
  */
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -32);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -36);
  intake.move(120);
  chassis.turn_to_point(-24, -36);
  chassis.drive_to_point(-24, -36);


}



void skills() {
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, 24);
}




void blueSWPGoal(){
  /*chassis.drive_to_point(0, 8, 14, 0, 1, 200, 500);
  //intake.move(400);
  chassis.drive_to_point(0, 18, 14, 0, 1, 200, 500);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_point(-60, 40, 0, 14, 1, 500, 700);
  chassis.set_coordinates(0,0,0);
  chassis.turn_to_point(24, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-24, 24, 14, 0, 1, 500, 700);
  pros::delay(100);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(1000);
  chassis.turn_to_point(-48, 20, 0, 14, 1, 500, 700);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-48, 20, 14, 0, 1, 500, 700);
  pros::delay(600);
  intake.move(0);
  chassis.turn_to_point(-40, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-48, 41, 14, 0, 1, 500, 700);
  pneumatics.clench_v(1);
  pros::delay(400);
  intake.move(600);
  chassis.drive_to_point(-48, 14, 14, 0, 1, 500, 700);
  pneumatics.clench_v(0);
  pros::delay(200);
  chassis.turn_to_point(45,-20, 0, 14, 1, 500, 700);
  intake.move(-600);
  chassis.drive_to_point(45,-20, 14, 0, 1, 500, 700);
  chassis.turn_to_point(40,29);
  intake.move(600);
  chassis.drive_to_point(40,29, 14, 0);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_point(100,20);
  chassis.drive_to_point(24,26);
  pneumatics.clench_v(1);
  intake.move(600);
  chassis.drive_to_point(0,48);*/
}
