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
		sprite_->InitSprite("./resource/CharacterSprite.png");
		sprite_->SetSpriteRect(0, 0, 24, 24);
		trs->SetPos(1, 1);
		trs->SetSize(100, 100);
		GameManager::getinstance()->map->GetMap()[0]->tiles[0]->onCharacter = this;
		onTile = GameManager::getinstance()->map->GetMap()[0]->tiles[0];
		SpriteState = 0;
		GameManager::getinstance()->p_x = trs->x;
		GameManager::getinstance()->p_y = trs->y;
	}

	~Player();
	
	Tile* onTile;

	void GetDamaged(int damage);

	void move(Tile* tile, int dir);
	void Attack(Character* monster);

	void CheckIsThereEnemy();

	void Update() {
		HandleEvents();
	}
	void HandleEvents();
	
	int SkillState;
	int SpriteState;
	virtual void Render();
private:
	InputComponent* input_;
	SpriteComponent* sprite_;
};
