#pragma once
#include"Object.h"
class Object;

class Tile : Object
{
	Tile(std::string name) : Object(name) {
		sprite = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite);
		sprite->InitSprite("C:/Users/MSI/source/repos/team_Project/team_Project/resource/wall.png");

	}
	bool IsWalkable;

	void Update();

private:
	SpriteComponent* sprite;
};

