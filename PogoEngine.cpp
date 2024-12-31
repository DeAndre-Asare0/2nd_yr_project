#include "PogoEngine.h"

PogoEngine::PogoEngine()
{

}

PogoEngine::~PogoEngine()
{

}

void PogoEngine::init(int x, int y, int speed, int Enemy_Spawn)
{
	_x = x;
	_y = y;
	_speed = speed;
	_Enemy_Spawn = Enemy_Spawn;
	//_enemy_A_x = enemy_A_x;
	//_enemy_A_y = enemy_A_y;
	_player.init(_x, _y, _speed);
	//_enemy.init_enemy_A(_enemy_A_x, _enemy_A_y);
	_enemy.init_enemy_vector(_Enemy_Spawn);

}

void PogoEngine::read_input(Gamepad& pad)
{
	_d = pad.get_direction();
	_mag = pad.get_mag();
}

void PogoEngine::draw(N5110& lcd)
{
	lcd.drawRect(0, 0, WIDTH, HEIGHT, FILL_TRANSPARENT);
	_player.draw(lcd);
	_enemy.draw(lcd);
}


void PogoEngine::update(N5110 &lcd,Gamepad& pad)
{
	_player.update(_d, _mag);
	_enemy.update();
	fire(lcd, _d);

}

void PogoEngine::fire(N5110& lcd, Direction d)
{
	if (d == E)
	{
		Player_Projectile _pp = _proj.Fire_Projectiles(_y);
		_Projectiles.push_back(_pp);
		for (int i; i < _Projectiles.size(); i++)
		{
			lcd.setPixel(_Projectiles[i].player_shot_x, _Projectiles[i].player_shot_y, true);
			printf("shot position %d\n", _Projectiles[i].player_shot_x);
		}
		for (int j; j < _Projectiles.size(); j++) 
		{
			_Projectiles[j].player_shot_x += _Projectiles[j].player_shot_speed;
			printf("new shot position is %d\n", _Projectiles[j].player_shot_x);
		}
	}


}