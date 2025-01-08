#include "Projectile.h"


Projectile::Projectile()
{

}

Projectile::~Projectile()
{

}


Player_Projectile Projectile::Fire_Projectiles(int y)
{
	_pp.player_shot_x = 25;
	_pp.player_shot_y = y + 3;
	_pp.player_shot_speed = 5;
	return _pp;
}
/*
void Projectile::off_screen(int erase)
{
	_Projectiles.erase(_Projectiles.begin() + erase);
}
*/
/*
void Projectile::init(int player_shot_x, int player_shot_speed)
{
	_player_shot_y = _player.get_y() + 3;
	_player_shot_x = player_shot_x;
	_player_shot_speed = player_shot_speed;
}

int *Projectile::get_projectile_sprite()
{
	{
		static int ProjectileSprite[3][7] = {
			{0,0,0,0,1,1,0},
			{1,1,1,1,1,1,1},
			{0,0,0,0,1,1,0},

		};
		return *ProjectileSprite;
	}
}

void Projectile::draw(N5110& lcd)
{
	lcd.drawSprite(_player_shot_x,_player_shot_y,3,7,(int*)ProjectileSprite);
}

void Projectile::update(bool _A)
{
	if (_A == true)
	{
		printf("missile released");
		_player_shot_x += _player_shot_speed;

		if (_player_shot_x > 77)
		{
			init(_player_shot_x, _player_shot_speed);
		}



	}
}
*/