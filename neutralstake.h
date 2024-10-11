#include "main.h"

class Neutral_Stake{
    public:
    pros::Motor neutral_stake_mtr;
    pros:: Rotation neutral_stake_rot;
    Neutral_Stake(int8_t neutral_stake_mtr_grp, int8_t neutral_stake_rot_port);

    void neutral_stake_control();
    void initialize();
    void move(double velocity);

};