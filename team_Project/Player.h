#pragma once
#include"Character.h"
#include"Components.h"
class Object;

class GameOverScreen : public Object {
public:
	GameOverScreen(std::string name) : Object(name) {
		sprite_ = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
		sprite_->InitSprite("./resource/GameOver_screen.png");
		sprite_->SetSpriteRect(0, 0, 320, 180);

		SDL_SetTextureAlphaMod(sprite_->textr, 0);
	}

	void Update();
	void Render();

private:
	int i = 0;
	SpriteComponent* sprite_;
};

class Player : public Character
{
public:
	Player(std::string name) : Character(name) {
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
		input_ = objf::CreateComp<InputComponent>("InputComponent");
		addComponent(input_);
		sprite_ = objf::CreateComp<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
		sprite_->InitSprite("./resource/GP_MainSheet.png");
		sprite_->SetSpriteRect(0, 96, 24, 24);
		trs->SetSize(100, 100);
		SpriteState = IDLE;
		SKillOn = false;

		gameover_ = new GameOverScreen("game_over");
	}

	~Player();

	Tile* onTile;

	void GetDamaged(int damage);

	void move(Tile* tile, int dir);
	void Attack(Character* monster);

	void CheckIsThereEnemy();

	void Update() {
		HandleEvents();
		if (!IsAlive) {
			gameover_->Update();
		}
	}
	void HandleEvents();
	void SetMotion(States st);

	void Skill(SDL_Event event);
	bool SKillOn;

	Skills SkillState;
	States SpriteState;
	
	virtual void Render();
private:
	InputComponent* input_;
	SpriteComponent* sprite_;
	GameOverScreen* gameover_;
};

