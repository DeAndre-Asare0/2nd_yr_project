#ifndef POGOENGINE_H
#define POGOENIGNE_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Pogo.h"
#include "Projectile.h"
#include "Enemy.h"

class PogoEngine
{

public:

	PogoEngine();
	~PogoEngine();

	void init(int x, int y, int speed, int Enemy_Spawn);
	void read_input(Gamepad& pad);
	void update(N5110 &lcd,Gamepad& pad);
	void draw(N5110& lcd);
	void fire(N5110& lcd,Direction d);


private:
	Enemy _enemy;
	Pogo _player;
	Projectile _proj;
	int _player_x;

	Direction _d;
	float _mag;
//	int _enemy_A_x;
//	int _enemy_A_y;
//	bool _A;
	std::vector<Player_Projectile> _Projectiles;
	Player_Projectile _pp;
	int _x;
	int _y;
	int _Enemy_Spawn;
	int _speed;

};
#endif