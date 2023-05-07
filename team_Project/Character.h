#pragma once
#include"Object.h"
class Object;
class Character : public Object
{
public:
	Character(std::string name) : Object(name){
		hp = 0;
		max_hp = 0;
		stamina = 0;
		max_stamina = 0;
	}
	int hp, max_hp;
	int stamina, max_stamina;
	bool IsAlive;
	virtual void Update() = 0;
	virtual void GetDamaged(int damage) = 0;
};

