#include "main.h"

class Pneumatics{
   public:
   pros::adi::DigitalOut clench;
   pros::adi::DigitalOut climb;
   Pneumatics(pros::adi::DigitalOut clench_port, pros::adi::DigitalOut climb_port);

   void clench_initialize();
   void clench_control();
   void clench_v(int value);

   void climb_initialize();
   void climb_control();
   void climb_v(int value);
};