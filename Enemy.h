#ifndef ENEMY_H
#define ENEMY_H


#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include <vector>


struct enemies
{
	int enemy_x;
	int enemy_y;
};

class Enemy
{
public:

	Enemy();

	~Enemy();
//	void init_enemy_A(int enemy_A_x, int enemy_A_y);
	int* get_enemy_sprite();
	void draw(N5110& lcd);
	//void create_enemies();
	void init_enemy_vector(int Enemy_Spawn);

	void update();

private:

	int EnemySprite;
	int _Enemy_Spawn;
//	int _enemy_A_x;
//	int _enemy_A_y;

	std::vector<enemies> _enemies;

};


#endif