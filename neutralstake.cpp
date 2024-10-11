#include "main.h"

Neutral_Stake::Neutral_Stake(int8_t neutral_stake_grp, int8_t neutral_stake_rot_port) 
    : neutral_stake_mtr(neutral_stake_grp), neutral_stake_rot(neutral_stake_rot_port) {
        neutral_stake_mtr.set_brake_mode_all (pros::E_MOTOR_BRAKE_HOLD);
    }

void Neutral_Stake::neutral_stake_control() {
    if (neutral_stake_rot.get_angle() >= 14000 && neutral_stake_rot.get_angle() <= 35400){
             while(!(neutral_stake_rot.get_angle() <= 14000 && neutral_stake_rot.get_angle() >= 13500)){
                    neutral_stake_mtr.move(-80);
             }
             neutral_stake_mtr.move(0);
    }

    if (master.get_digital(DIGITAL_Y))
        neutral_stake_mtr.move(-420);
    else if (master.get_digital(DIGITAL_B))
        neutral_stake_mtr.move(420);
    else {
        neutral_stake_mtr.move(0);

        neutral_stake_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        neutral_stake_mtr.brake();
        printf("motorbrakemode: %d\n", neutral_stake_mtr.get_brake_mode());
    }
        // printf("motorbrakemode: %d\n", neutral_stake_mtr.get_position());
        // printf("Tick Position: %ld \n", neutral_stake_rot.get_angle());
     if (master.get_digital(DIGITAL_A)){

         while (neutral_stake_rot.get_angle() >= 2650 || neutral_stake_rot.get_angle() <= 2550) {
           if (neutral_stake_rot.get_angle() >= 2650){
                if (neutral_stake_rot.get_angle() >= 35500 && neutral_stake_rot.get_angle() <= 35999)
                    neutral_stake_mtr.move(60);
                else
                    neutral_stake_mtr.move(-60);
           }
           else if (neutral_stake_rot.get_angle() <= 2550)
                neutral_stake_mtr.move(60);
        }
        neutral_stake_mtr.move(0);
    }
}

void Neutral_Stake::initialize() {
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset();
    neutral_stake_rot.set_data_rate(5);
    neutral_stake_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    neutral_stake_mtr.brake();
}

void Neutral_Stake::move(double voltage) {
    neutral_stake_mtr.move_velocity(voltage * 100);
}