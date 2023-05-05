#pragma once
#include"Object.h"
class Object;

class Tile : Object
{
	Tile(std::string name) : Object(name) {
		sprite = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite);
		sprite->InitSprite("./resource/wall.png");

	}
	bool IsWalkable;

	void Update();

private:
	SpriteComponent* sprite;
};

