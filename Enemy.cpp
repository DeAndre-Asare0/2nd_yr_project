#include "Enemy.h"

Enemy::Enemy()
{

}
Enemy::~Enemy()
{

}

int* Enemy::get_enemy_sprite()
{
	static int EnemySprite[7][8] = 
	{
	 {0,0,1,1,0,1,1,0},
	 {0,1,0,1,1,0,1,0},
	 {0,1,0,1,1,0,1,1},
	 {1,1,1,1,1,1,1,1},
	 {0,1,1,0,0,1,1,1},
	 {0,1,0,1,1,0,1,1},
	 {0,0,1,1,1,1,1,0},
	};
	return *EnemySprite;
}
/*
void Enemy::init_enemy_A(int enemy_A_x, int enemy_A_y)
{
	_enemy_A_x = enemy_A_x;
	_enemy_A_y = enemy_A_y;
}
*/
void Enemy::init_enemy_vector(int Enemy_Spawn)
{
	_Enemy_Spawn = Enemy_Spawn;
	if (_Enemy_Spawn <15)
	{
		_Enemy_Spawn++;
	}

	std::vector<enemies> _enemies;
	
	if (_Enemy_Spawn >= 15)
	{

		_enemies.push_back(enemies());
		for (int i = 0; i < _enemies.size(); i++)
		{
			_enemies[i].enemy_x = 75;
			_enemies[i].enemy_y = rand() % 36;
		}
	}
}

void Enemy::draw(N5110& lcd)
{
	for (size_t i = 0; i < _enemies.size(); i++)
	{
		int* EnemySprite;
		EnemySprite = get_enemy_sprite();
		lcd.drawSprite(_enemies[i].enemy_x, _enemies[i].enemy_y, 7, 8, (int*)EnemySprite);
	}
}

void Enemy::update()
{
	for (size_t i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].enemy_x -= 10;
	}
}