#pragma once
#include"Object.h"

class Object;
class Character;

class Tile : public Object
{
public:
	Tile(std::string name, int x, int y) : Object(name) {
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
		trs->SetSize(100, 100);
		sprite = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite);
		sprite->InitSprite("./resource/WallSprite.png");
		parameter = 1.0f;
		mapX = x;
		mapY = y;
		onCharacter = NULL;
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
	void Render();
	SpriteComponent* GetSprite() { return sprite; }
	Character* onCharacter;

private:
	SpriteComponent* sprite;

};

