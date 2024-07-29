#include "main.h"

class Intake{
    public:
    pros::MotorGroup intake;
    Intake(std::initializer_list<std::int8_t> intake_grp);

    void intake_control();
    void initialize();
    void move(float velocity);
        
};