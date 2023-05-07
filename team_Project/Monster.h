#pragma once
#include"Character.h"
class Monster:public Character
{
public:
	Monster(std::string name) : Character(name) {
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
		sprite_ = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
		sprite_->InitSprite("./resource/wall.png");
		sprite_->SetSpriteRect(0, 0, 100, 100);
		trs->SetPos(500, 0);
		trs->SetSize(100, 100);
	}

	void move();
	void GetDamaged(int damage);
	void Update() {}
	void Render();
private:
	SpriteComponent* sprite_;
};

