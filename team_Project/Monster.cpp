#include"stdafx.h"
#include "Monster.h"
void Monster::Render() {
	sprite_->Render();
}
void Monster::GetDamaged(int damage) {
	hp -= damage;
	std::cout << "HP : "<< hp << " monster jonna cheo majat Sawyo!\n";
	if (hp <= 0) {
		IsAlive = false;
		hp = 0;
	}
}

void Monster::SetPos(int x, int y) {
	trs->SetPos(x, y);
}


void Monster::Update() {
	GameManager* gm = GameManager::getinstance();
	if (!GameManager::getinstance()->P_Turn) {
		gm->PF->ResetPath(gm->path);
		gm->PathFind(trs->x, trs->y, gm->p_x, gm->p_y);
		gm->TestHwakIn();
		
		trs->x = gm->path->positions[gm->path->positions.size()-2]->mapX;
		trs->y = gm->path->positions[gm->path->positions.size()-2]->mapY;


		gm->P_Turn = true;


	}
}

void Monster::move(Tile* tar, int dir) {
	onTile->onCharacter = NULL;
	switch (dir)
	{
	default:
		break;
	case 1:
		onTile = onTile->dl;
		onTile->onCharacter = this;
		break;
	case 2:
		onTile = onTile->d;
		onTile->onCharacter = this;
		break;
	case 3:
		onTile = onTile->dr;
		onTile->onCharacter = this;
		break;
	case 4:
		onTile = onTile->l;
		onTile->onCharacter = this;
		break;
	case 5:
		onTile = onTile;
		onTile->onCharacter = this;
		break;
	case 6:
		onTile = onTile->r;
		onTile->onCharacter = this;
		break;
	case 7:
		onTile = onTile->ul;
		onTile->onCharacter = this;
		break;
	case 8:
		onTile = onTile->u;
		onTile->onCharacter = this;
		break;
	case 9:
		onTile = onTile->ur;
		onTile->onCharacter = this;
		break;
	}

}

void Monster::Attack(Character* player) {
	player->GetDamaged(10);
}