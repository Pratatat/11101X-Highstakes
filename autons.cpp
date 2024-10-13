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
  chassis.drive_kp = 0.80;
  chassis.drive_kd = 0.173;
  chassis.drive_settle_error = 3;
  chassis.turn_max_voltage = 10;
  chassis.turn_kp = 0.25;
  chassis.turn_ki = 0;
  chassis.turn_kd = 2;
  chassis.turn_settle_error = 3;
  chassis.turn_settle_time = 300;

}

void drive_test(){
  odom_constants(); 
  chassis.drive_distance(24);
  pros::delay(100);
  chassis.turn_to_angle(90);
   pros::delay(100);
  chassis.drive_distance(24);
   pros::delay(100);
  chassis.turn_to_angle(180);
   pros::delay(100);
  chassis.drive_distance(24);
   pros::delay(100);
  chassis.turn_to_angle(270);
   pros::delay(100);
  chassis.drive_distance(24);
   pros::delay(100);
  chassis.turn_to_angle(360);
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
  pros::delay(500);
  chassis.drive_to_point(0,24,10,0);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(24,24,0,10);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.drive_to_point(24,24,10,0);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(24,0,0,10);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.drive_to_point(24,0,10,0);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(0,0,0,10);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.drive_to_point(0,0,10,0);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(0,24,0,10);
  pros::delay(200);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl;
}

void redSWP(){
  odom_constants();
  chassis.set_coordinates(0,0, 0);
  chassis.drive_to_point(0, -27.5);
  pros::delay(100);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(28.5, -31);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(28.5, -31,14,0);
  pros::delay(1250);
  chassis.turn_to_point(-24, -5);
  intake.move(0);
  chassis.drive_to_point(0, -15);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_to_point(-24, -5);
  chassis.turn_to_point(-2, 20);
  chassis.drive_to_point(-40, -30, 11, 0, 1, 300, 600);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(-51, -24);
  intake.move(600);                           
  chassis.drive_to_point(-51, -24,12,0, 1, 300, 600);
  pros::delay(1000);
  intake.move(0);
  chassis.turn_to_point(-16.5, -25.5,0,12);
  intake.move(600);
  chassis.drive_to_point(-16.5, -25.5,7.5,0);
  intake.move(0);
  pneumatics.clench_v(0);
  /*
  Alliance stake swp
  chassis.drive_to_point(0,13.7,9,0);
  pros::delay(200);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(455);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-50.5,35);
  intake.move(400);
   pros::delay(200);
  chassis.drive_to_point(-50.5,35, 12, 0, 1, 300, 1300);
   pros::delay(200);
  intake.move(0);
  chassis.turn_to_point(-150,37.5); 
  pros::delay(200);
  chassis.drive_to_point(-28.5,36.8, 11, 0, 1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(250);
  chassis.drive_to_point(-37,37, 14, 0);
  pros::delay(150);
  chassis.turn_to_point(-42.5,55);
  chassis.drive_to_point(-42.5,49, 14, 0,1, 300, 600);
  pros::delay(600);
  chassis.drive_to_point(-38.5,38.5, 14, 0,1, 300, 600);
  pros::delay(200);
  chassis.turn_to_point(-47,49.5,0,14,1, 300, 600);
  chassis.drive_to_point(-47,49.5, 14, 0,1, 300, 600);
  pros::delay(630);
  chassis.turn_to_point(-22.5,48,0,9);
   chassis.set_brake_mode(MOTOR_BRAKE_HOLD);
  intake.move(0);
  chassis.drive_to_point(-22.5,48,14,0);
  chassis.turn_to_point(0,65);
  */
}

void redFullArenaSWP(){
  odom_constants();
  chassis.drive_distance(-12);
  pros::delay(100);
  chassis.right_swing_to_angle(30);
  pros::delay(100);
  chassis.drive_distance(-15);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(650);
  chassis.turn_to_angle(285);
  pros::delay(100);
  chassis.drive_distance(25);
  pros::delay(800);
  chassis.turn_to_angle(30);
  pros::delay(100);
  chassis.drive_distance(30);
}
void redRightQual(){
  odom_constants();
  chassis.drive_distance(-14);
  pros::delay(100);
  chassis.right_swing_to_angle(19.5);
  pros::delay(100);
  chassis.drive_distance(-16);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(650);
  chassis.turn_to_angle(275);
  pros::delay(100);
  chassis.drive_distance(26);
  pros::delay(2000);
  chassis.turn_to_angle(90);
  pros::delay(100);
  intake.move(600);
  chassis.drive_distance(40,0,4.5,0);
  pneumatics.clench_v(0);
  /*
   pros::delay(100);
  chassis.turn_to_angle(135);
  pros::delay(100);
  chassis.drive_distance(8);
  intake.move(0);
  pneumatics.clench_v(0);
  */
  
  /*
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
  chassis.drive_to_point(10, -36);
  pneumatics.clench_v(0);
  intake.move(0);
  */
}

void redRightElim(){
  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -27,14,0);
  pros::delay(200);
  chassis.turn_to_point(-30,24);
  pros::delay(200);
  chassis.drive_to_point(14.25,-40.25,14,0,1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(500);
  chassis.turn_to_point(14, -20);
  chassis.drive_to_point(14, -30,14,0,1, 300, 600);
  pros::delay(150);
  intake.move(0);
  // changed
  chassis.turn_to_point(48,-48);
  chassis.drive_to_point(10,18,14,0,1, 300, 600);
  pneumatics.clench_v(0);
  pros::delay(150);
  chassis.drive_to_point(14, -30,14,0,1, 300, 600);
  pros::delay(150);
  //changed
  chassis.turn_to_point(-60,-25);
  pros::delay(150);
  chassis.drive_to_point(21,-27,14,0,1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(400);
  chassis.turn_to_point(-5,-22);
  intake.move(0);
  chassis.drive_to_point(-5,-22,14,0,1, 300, 600);
  //chassis.turn_to_point(0,4);
  //pneumatics.doinker_v(1);
  //chassis.drive_to_point(-5.5,4);
  //pros::delay(250);
  //intake.move(0);
  //chassis.turn_to_point(-24,-60);
  //chassis.turn_to_point(120,-120);
*/

  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(600);
  pros::delay(1000);
  chassis.turn_to_point(-24, -30);
  chassis.drive_to_point(-24, -30);
  pros::delay(1200);
  intake.move(0);
  pneumatics.clench_v(0);
  /*
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
  odom_constants();
  chassis.drive_distance(-14);
  pros::delay(100);
  chassis.right_swing_to_angle(19.5);
  pros::delay(100);
  chassis.drive_distance(-16);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(1000);
  chassis.turn_to_angle(92);
  pros::delay(100);
  chassis.set_coordinates(0, 0, 0);
  pros::delay(100);
  chassis.drive_to_point(0, 24, 14, 0,1, 300, 600);
  pros::delay(1000);
  chassis.drive_to_point(0, 15, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(18,15);
  intake.move(600);
  pros::delay(100);
  chassis.drive_to_point(18,15, 14, 0,1, 300, 600);
  pros::delay(1000);
  chassis.drive_to_point(0, 15, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(0,200);
  pros::delay(100);
  chassis.drive_to_point(0, 22, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(19,22);
  pros::delay(100);
  chassis.drive_to_point(19,22, 14, 0,1, 300, 600);
  pros::delay(1100);
  chassis.drive_to_point(0, 15, 14, 0,1, 300, 600);
  chassis.turn_to_point(-24,-24);
    /*
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -32, 14, 0,1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(450);
  chassis.turn_to_point(50, -24);
  chassis.drive_to_point(24, -24,14,0,1,300,600);
  pros::delay(400);
  chassis.turn_to_point(17, -120);
  chassis.drive_to_point(17, -45,11,0,1,300,600);
  pros::delay(500);
  chassis.drive_to_point(24, -35,11,0,1,300,600);
  pneumatics.clench_v(0);
  chassis.turn_to_point(36, -120);
  intake.move(250);
  chassis.drive_to_point(36, -46.5,11,0,1,300,600);
  pros::delay(200);
  chassis.turn_to_point(0,0);
  intake.move(0);
  chassis.drive_to_point(0,0,14,0,1,300,600);
  pros::delay(300);
  chassis.turn_to_point(-100,0);
  */
}

void blueSWP(){
  odom_constants();
  chassis.set_coordinates(0,0, 0);
  chassis.drive_to_point(0, -27.5);
  pros::delay(75);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(-27, -28,0,14);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(-27, -28,14,0);
  pros::delay(1200);
  intake.move(0);
  chassis.turn_to_point(24, -5);
  chassis.drive_to_point(0, -15);
  pneumatics.clench_v(0);
  pros::delay(150);
  chassis.drive_to_point(24, -5);
  chassis.turn_to_point(-4, 20);
  chassis.drive_to_point(41, -35, 9.5, 0, 1, 300, 600);
  pros::delay(100);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(56, -31.5);
  intake.move(600);                           
  chassis.drive_to_point(56, -31.5,11,0, 1, 300, 600);
  pros::delay(1300);
  chassis.turn_to_point(17, -31);
  chassis.drive_to_point(17, -31,5,0);
  pneumatics.clench_v(0);
  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0,15.4,9,0);
  pros::delay(300);
  chassis.turn_to_point(100,13.5);
  pneumatics.clench_v(1);
   pros::delay(150);
  chassis.drive_to_point(-5,15, 4, 0,1, 400, 800);
  intake.move(600);
  pros::delay(500);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  intake.move(600);
  chassis.turn_to_point(63,40);
   pros::delay(150);
  chassis.drive_to_point(52,40, 14, 0,1, 300, 1300);
   pros::delay(220);    
   intake.move(0);
  chassis.turn_to_point(150,41); 
  pros::delay(200);
  chassis.drive_to_point(31, 41, 9.5, 0,1, 300, 600);
  pros::delay(50);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(250); 
  chassis.drive_to_point(37,37, 14, 0,1, 300, 600); 
  pros::delay(200);
  chassis.turn_to_point(43.5,55, 0, 14,1, 300, 600);
  chassis.drive_to_point(43.5,49, 14, 0,1, 300, 600);
  pros::delay(550);
  chassis.drive_to_point(40.5,38.5, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(49,49.5,0,14,1, 300, 600);
  chassis.drive_to_point(49,49.5, 14, 0,1, 300, 600);
  pros::delay(700);
  chassis.turn_to_point(27,48);
  chassis.drive_to_point(27,48,14,0);
  chassis.set_brake_mode(MOTOR_BRAKE_HOLD);
  chassis.turn_to_point(0,65);
  pneumatics.clench_v(0);
  chassis.drive_distance(3.5);
  */
}


void blueLeftQual() {
  odom_constants();
  chassis.drive_distance(-14);
  pros::delay(100);
  chassis.right_swing_to_angle(19.5);
  pros::delay(100);
  chassis.drive_distance(-16);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(650);
  chassis.turn_to_angle(92);
  pros::delay(100);
  chassis.drive_distance(26.5);
  pros::delay(800);
  chassis.turn_to_angle(270);
  pros::delay(100);
  chassis.drive_distance(40,0,4.5,0);
  pneumatics.clench_v(0);
 
  /*
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -26.5, 7, 0);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(600);
  pros::delay(1000);
  chassis.turn_to_point(24, -28);
  chassis.drive_to_point(24, -28);
  pros::delay(1200);
  chassis.turn_to_point(0, -28);
  chassis.drive_to_point(0, -28);
  chassis.turn_to_point(-24, -52);
  chassis.drive_to_point(-8, -35);
  pneumatics.clench_v(0);
  */
}
void blueRightElim(){
  odom_constants();
  chassis.drive_distance(-14);
  pros::delay(100);
  chassis.right_swing_to_angle(19.5);
  pros::delay(100);
  chassis.drive_distance(-16);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(650);
  chassis.turn_to_angle(278);
  pros::delay(100);
  chassis.set_coordinates(0, 0, 0);
  pros::delay(100);
  chassis.drive_to_point(0, 24, 14, 0,1, 300, 600);
  pros::delay(1000);
  chassis.drive_to_point(0, 15, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(-18,16);
  intake.move(10000);
  pros::delay(100);
  chassis.drive_to_point(-18,16, 14, 0);
  pros::delay(1400);
  chassis.drive_to_point(0, 16, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(0,200);
  pros::delay(100);
  chassis.drive_to_point(0, 22.5, 14, 0,1, 300, 600);
  pros::delay(100);
  chassis.turn_to_point(-18.5,22);
  pros::delay(100); 
  chassis.drive_to_point(-18.5,22, 14, 0);
  pros::delay(1500);
  chassis.drive_to_point(0, 15, 14, 0,1, 300, 600);
}

void blueLeftElim() {
  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -27,14,0);
  pros::delay(200);
  chassis.turn_to_point(37.5,24);
  pros::delay(200);
  chassis.drive_to_point(-16.25,-39.75,14,0,1, 300, 600);
   pros::delay(200);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(500);
  chassis.turn_to_point(-14, -20);
  chassis.drive_to_point(-14, -30,14,0,1, 300, 600);
  pros::delay(150);
  intake.move(0);
   // changed
  chassis.turn_to_point(-48,-48);
  chassis.drive_to_point(-10,18,14,0,1, 300, 600);
  pneumatics.clench_v(0);
  pros::delay(150);
  chassis.drive_to_point(-14, -30,14,0,1, 300, 600);
  pros::delay(150);
  //changed
  chassis.turn_to_point(60,-30);
  pros::delay(150);
  chassis.drive_to_point(-21,-27,14,0,1, 300, 600);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(400);
  chassis.turn_to_point(5,-22);
  intake.move(0);
  chassis.drive_to_point(5,-22,14,0,1, 300, 600);
 */
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(600);
  pros::delay(1000);
  chassis.turn_to_point(24, -28);
  chassis.drive_to_point(24, -28);
  pros::delay(1200);
  pneumatics.clench_v(0);
  chassis.turn_to_point(24,0);
}


void skills() {
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, 24);
}
