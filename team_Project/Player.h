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
		hpbar = objf::CreateComp<HPBAR>("HPBAR");
		addComponent(hpbar);
		stbar = objf::CreateComp<STBAR>("STBAR");
		addComponent(stbar);

		sprite_->InitSprite("./resource/GP_MainSheet.png");
		sprite_->SetSpriteRect(0, 96, 24, 24);
		trs->SetSize(100, 100);
		SpriteState = IDLE;
		SKillOn = false;
		GameOverScreenOn = false;
		this->hp = 100;
		this->max_hp = 100;
		MaxStamina = 100;
		stamina = 100;

		hpbar->set_hp(hp);
		hpbar->set_mh(max_hp);

		stbar->set_st(stamina);
		stbar->set_ms(MaxStamina);

	}

	~Player();

	Tile* onTile;

	bool GetDamaged(int damage);

	void move(Tile* tile, int dir);
	void move(Tile* tar);
	void Attack(Character* monster);
	void Attack(Character* monster, int dam);

	void CheckIsThereEnemy();

	void Update() {
		if (!IsAlive) {
			if (GameOverScreenOn) {
				return;
			}
			objf::CreateObj<GameOverScreen>("GameOverScreen");
			GameManager::getinstance()->sm->gameover_music();
			GameOverScreenOn = true;
		}
		else
			HandleEvents();
	}
	void HandleEvents();
	void SetMotion(States st);
	void WallRun(SDL_Event event, GameManager* &gm);

	void Skill(SDL_Event event);
	bool SKillOn;
	bool GameOverScreenOn;
	int MaxStamina;
	int stamina;

	Skills SkillState;
	States SpriteState;
	
	virtual void Render();
private:
	InputComponent* input_;
	SpriteComponent* sprite_;
	HPBAR* hpbar;
	STBAR* stbar;
};

