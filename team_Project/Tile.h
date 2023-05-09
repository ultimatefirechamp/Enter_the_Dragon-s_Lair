#pragma once
#include"Object.h"
class Object;

class Tile : public Object
{
public:
	Tile(std::string name) : Object(name) {
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
		trs->SetSize(100, 100);
		sprite = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite);
		sprite->InitSprite("./resource/wall.png");

	}
	
	int mapX, mapY;
	float parameter;

	Tile* u;
	Tile* ur;
	Tile* ul;
	Tile* d;
	Tile* dr;
	Tile* dl;
	Tile* r;
	Tile* l;
	
	Tile* parent;



	float gVal, hVal, fVal;

	bool open, closed;
	bool IsWalkable;

	void Update();

private:
	SpriteComponent* sprite;
};

