#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include <vector>


struct Player_Projectile
{
	int player_shot_x;
	int player_shot_y;
	int player_shot_speed;
};


class Projectile
{


public:


	Projectile();

	~Projectile();

	Player_Projectile _pp;
	Player_Projectile Fire_Projectiles(int y);
	//void off_screen(int erase);
	

private:
	int _player_shot_x;
	int _player_shot_y;
	int _player_shot_speed;


};
#endif