#include "main.h"

Intake::Intake(std::initializer_list<std::int8_t> intake_grp) 
    : intake(intake_grp) {}

void Intake::intake_control() {
    move(0);
    if (master.get_digital(DIGITAL_L1)){ 
        intake.move_velocity(600); }
    if (master.get_digital(DIGITAL_L2)){
        intake.move_velocity(-600); }
}

void Intake::initialize() {
    intake.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void Intake::move(float velocity) {
    intake.move_velocity(velocity);
}