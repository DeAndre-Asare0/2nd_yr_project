#ifndef POGO_H
#define POGO_H


#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"


class Pogo
{

public:

	Pogo();

	~Pogo();


	void init(int x, int y, int speed);
	int* get_pogo_sprite();
	void draw(N5110& lcd);

	void update(Direction d, float mag);

	Vector2D get_pos();



	//std::vector<Player_Projectile> projectile_pos();

private:

	int _x;
	int _y;
	bool _A;
	int _speed;
	Vector2D _player_p;


};
#endif