#pragma once
#include"Character.h"
#include"Components.h"

class Player : public Character
{
public:
	Player(std::string name) : Character(name){
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
		input_ = objf::CreateComp<InputComponent>("InputComponent");
		addComponent(input_);
		sprite_ = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
		sprite_->InitSprite("C:/Users/MSI/source/repos/team_Project/team_Project/resource/wall.png");
		sprite_->sr.x = 0;
		sprite_->sr.y = 0;
		sprite_->sr.w = 100;
		sprite_->sr.h = 100;
		trs->SetRect(0, 0, 70, 70);
	}

	~Player();

	void Update() {
		input_->HandleEvent();
	}

	
	virtual void Render();
private:
	int max_hp, hp;
	int max_stamina, stamina;
	InputComponent* input_;
	SpriteComponent* sprite_;
};
