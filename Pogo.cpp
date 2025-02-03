#include "Pogo.h"

Pogo::Pogo()
{

}

Pogo::~Pogo()
{

}

void Pogo::init(int x, int y, int speed)
{
	_x = x;
	_y = y;
	_speed = speed;
}


int* Pogo::get_pogo_sprite()
{
	static int PogoSprite[6][8] = {
		{0,1,1,0,1,1,0,0},
		{1,1,0,1,1,0,1,0},
		{1,1,1,1,1,1,1,1},
		{1,1,0,1,1,1,1,1},
		{1,1,1,0,0,0,1,1},
		{1,1,1,1,1,1,1,0},
	};
	return *PogoSprite;
}

void Pogo::draw(N5110& lcd)
{
	int* PogoSprite;
	PogoSprite = get_pogo_sprite();
	lcd.drawSprite(_x, _y, 6, 8, (int*)PogoSprite);
}

void Pogo::update(Direction d, float mag)
{
	_speed = int(mag * 5.0f);


	if (d == N)
	{
		_y -= _speed;
	}
	if (d == S)
	{
		_y += _speed;
	}

	if (_y < 1)
	{
		_y = 1;
	}
	if (_y > 41)
	{
		_y = 41;
	}


}


Vector2D Pogo::get_pos()
{
	Vector2D _player_p = { _x,_y };
	return _player_p;
}




