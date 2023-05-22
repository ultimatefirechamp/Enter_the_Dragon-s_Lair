#pragma once
#include"Object.h"
class Object;
class Tile;
class Character : public Object
{
public:
	Character(std::string name) : Object(name) {
		IsAlive = true;
		hp = 0;
		max_hp = 0;
		stamina = 0;
		max_stamina = 0;
	}
	int hp, max_hp;
	int stamina, max_stamina;
	bool IsAlive;

	virtual void move(Tile* tile, int dir) = 0;
	virtual void Update() = 0;
	virtual void GetDamaged(int damage) = 0;
};
