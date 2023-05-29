#include "stdafx.h"
#include "InGameScene.h"

void InGameScene::InitScene() {
	GameManager* gm = GameManager::getinstance();
	gm->InitMap();
	gm->map->SetTile();
	Player* tmp =
	objf::CreateObj<Player>("Player");
	int x, y;
	x = 10;
	y = 10;
	tmp->GetTrans()->SetPos(x, y);
	gm->map->GetMap()[tmp->GetTrans()->x]->tiles[tmp->GetTrans()->y]->onCharacter = tmp;
	tmp->onTile = gm->map->GetMap()[tmp->GetTrans()->x]->tiles[tmp->GetTrans()->y];
	gm->p_x = x;
	gm->p_y = y;
}
InGameScene::~InGameScene() {
	objCol.clear();

}