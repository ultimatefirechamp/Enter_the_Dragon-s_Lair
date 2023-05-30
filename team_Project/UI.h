#pragma once
#include"stdafx.h"
#include"UI.h"

class UI : public Object {
public:
	UI(std::string name) : Object(name) {
		sprite_ = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
		sprite_->InitSprite("./resource/GP_MainSheet.png");
		sprite_->SetSpriteRect(2, 156, 159, 42);
	}

	void Update();
	void Render();

private:
	SpriteComponent* sprite_;
};
