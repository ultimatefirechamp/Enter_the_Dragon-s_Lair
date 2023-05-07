#pragma once
#include"Object.h"
class Monster:public Object
{
public:
	Monster(std::string name) : Object(name) {
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
		sprite_ = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
		sprite_->InitSprite("./resource/wall.png");
		sprite_->sr.x = 0;
		sprite_->sr.y = 0;
		sprite_->sr.w = 100;
		sprite_->sr.h = 100;
		trs->x = 500;
		trs->y = 0;
		trs->w = 100;
		trs->h = 100;
	}

	void Update() {}
	void Render();
private:
	SpriteComponent* sprite_;
};

