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
		sprite_->InitSprite("./resource/WallSprite.png");
		sprite_->SetSpriteRect(0, 0, 24, 24);
		trs->SetPos(0, 0);
		trs->SetSize(100, 100);
	}

	~Player();
	
	void GetDamaged(int damage);

	void move();
	void Attack(Character* monster);

	void Update() {
		input_->HandleEvent();
	}

	
	virtual void Render();
private:
	InputComponent* input_;
	SpriteComponent* sprite_;
};
