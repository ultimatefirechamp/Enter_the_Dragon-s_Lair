#pragma once
#include"Object.h"
class Object;
class Character : public Object
{
public:
	Character(std::string name) : Object(name){
		hp = 0;
		maxhp = 0;
		stamina = 0;
	}
	int hp, maxhp;
	int stamina;

	virtual void Update() = 0;

};

