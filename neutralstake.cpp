#include "main.h"

Neutral_Stake::Neutral_Stake(int8_t neutral_stake_grp, int8_t neutral_stake_rot_port) 
    : neutral_stake_mtr(neutral_stake_grp), neutral_stake_rot(neutral_stake_rot_port) {
        neutral_stake_mtr.set_brake_mode_all (pros::E_MOTOR_BRAKE_HOLD);
    }

void Neutral_Stake::neutral_stake_control() {
    if (neutral_stake_rot.get_angle() >= 14500 && neutral_stake_rot.get_angle() <= 35400){
             while(!(neutral_stake_rot.get_angle() <= 14500 && neutral_stake_rot.get_angle() >= 14000)){
                    neutral_stake_mtr.move(-80);
             }
            neutral_stake_mtr.move(0);
    }
    if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_rot.get_angle() <= 12000) {
            if (neutral_stake_position == 1) {
                intake.move(-120);
                pros::delay(45);
                intake.move(0);
                neutral_stake_position = 0;
            } neutral_stake_mtr.move(350);
        } 
    } else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move(-350);
    } else {
        neutral_stake_mtr.move(0);
    }
    if (master.get_digital(DIGITAL_A)) {
        while (neutral_stake_rot.get_angle() <= 2600 or neutral_stake_rot.get_angle() >= 35000) {
            neutral_stake_mtr.move(80);
        }
        while (neutral_stake_rot.get_angle() >= 3050) {
            neutral_stake_mtr.move(-100);
        } neutral_stake_mtr.move_velocity(0);
        neutral_stake_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

        neutral_stake_position = 1;


        /*if (neutral_stake_position == 0) {
            while (neutral_stake_rot.get_angle() <= 3850 or neutral_stake_rot.get_angle() >= 34000) {
                neutral_stake_mtr.move(325);
            }
            while (neutral_stake_rot.get_angle() >= 3900) {
                neutral_stake_mtr.move(-325);
            } neutral_stake_position = 1;
        } else {
            while (neutral_stake_rot.get_angle() <= 12000) {
                neutral_stake_mtr.move(350);
            } neutral_stake_position = 0;
        }*/
    }
}

void Neutral_Stake::initialize() {
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset();
    neutral_stake_rot.set_data_rate(5);
    neutral_stake_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    neutral_stake_position = 0;
}

void Neutral_Stake::move(double voltage) {
    neutral_stake_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    neutral_stake_mtr.move_velocity(voltage * 100);
}
