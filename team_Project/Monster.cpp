#include"stdafx.h"
#include "Monster.h"
void Monster::Render() {
	sprite_->Render();
	hpbar->Render();
}
void Monster::GetDamaged(int damage) {
	hp -= damage;
	hpbar->set_hp(hp);
	std::cout << "HP : " << hp << " monster jonna cheo majat Sawyo!\n";
	if (hp <= 0) {
		std::cout << "monster Juke O bow riot da\n";
		IsAlive = false;
		IsOn = false;
		onTile->onCharacter = NULL;
		hp = 0;
	}
}

void Monster::SetPos(int x, int y) {
	trs->SetPos(x, y);
}


void Monster::Update() {
	GameManager* gm = GameManager::getinstance();
	if (!this->IsAlive) {//if Dead

	}
	else if (!GameManager::getinstance()->P_Turn) {
		gm->PF->ResetPath(gm->path);
		gm->PathFind(trs->x, trs->y, gm->p_x, gm->p_y);
		gm->TestHwakIn();

		int x, y;
		x = gm->path->positions[gm->path->positions.size() - 2]->mapX;
		y = gm->path->positions[gm->path->positions.size() - 2]->mapY;

		if (gm->map->GetMap()[x]->tiles[y]->onCharacter == NULL) {
			trs->x = x;
			trs->y = y;
			move(gm->map->GetMap()[x]->tiles[y]);
		}
		else {
			gm->map->GetMap()[x]->tiles[y]->onCharacter->GetDamaged(10);
		}

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

void Monster::move(Tile* tar) {
	onTile->onCharacter = NULL;
	onTile = tar;
	onTile->onCharacter = this;
}


void Monster::Attack(Character* player) {
	player->GetDamaged(10);
}