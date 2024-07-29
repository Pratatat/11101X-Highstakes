#include "main.h"


Pneumatics::Pneumatics(pros::adi::DigitalOut clench_port, pros::adi::DigitalOut climb_port)
   : clench(clench_port),
   climb(climb_port) {}


void Pneumatics::clench_control() {
  if (master.get_digital(DIGITAL_R1)){
       clench_down = !clench_down;
       clench.set_value(clench_down);
       while (master.get_digital(DIGITAL_R1)) {
           pros::delay(util::DELAY_TIME);
       }
   }
}

void Pneumatics::clench_initialize() {
   clench.set_value(0);
}


void Pneumatics::clench_v(int value) {
   clench.set_value(value);
}


void Pneumatics::climb_control() {
  if (master.get_digital(DIGITAL_Y)){
       climb_open = !climb_open;
       climb.set_value(climb_open);
       while (master.get_digital(DIGITAL_Y)) {
           pros::delay(util::DELAY_TIME);
       }
   }
}

void Pneumatics::climb_initialize() {
   climb.set_value(0);
}


void Pneumatics::climb_v(int value) {
   climb.set_value(value);
}