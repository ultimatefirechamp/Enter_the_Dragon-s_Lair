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
		sprite_->InitSprite("./resource/CharacterSprite.png");
		sprite_->SetSpriteRect(0, 24, 24, 24);
		trs->SetPos(5, 1);
		trs->SetSize(100, 100);

		SetThisCharacterOnTile(5, 1);

	}

	void SetPos(int x, int y);
	void move(Tile* tar, int dir);
	void Attack(Character* player);
	void GetDamaged(int damage);
	void Update();
	void Render();
	void SetThisCharacterOnTile(int x, int y) {
		GameManager::getinstance()->map->GetMap()[x]->tiles[y]->onCharacter = this;
		onTile = GameManager::getinstance()->map->GetMap()[x]->tiles[y];
	}
private:
	Tile* onTile;
	SpriteComponent* sprite_;
};
