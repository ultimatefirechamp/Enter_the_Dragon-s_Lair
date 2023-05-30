#include "stdafx.h"
#include "InGameScene.h"
#include"Monster.h"

void InGameScene::InitScene() {
	GameManager* gm = GameManager::getinstance();
	gm->InitMap();
	gm->LoadMap("./resource/Test.txt");
	gm->map->SetTile();
	Player* tmp =
	objf::CreateObj<Player>("Player");
	int x, y;
	x = gm->SpawnPoint_x;
	y = gm->SpawnPoint_y;

	tmp->GetTrans()->SetPos(gm->SpawnPoint_x, gm->SpawnPoint_y);
	gm->map->GetMap()[tmp->GetTrans()->x]->tiles[tmp->GetTrans()->y]->onCharacter = tmp;
	tmp->onTile = gm->map->GetMap()[tmp->GetTrans()->x]->tiles[tmp->GetTrans()->y];
	gm->p_x = x;
	gm->p_y = y;
	Monster* m_tmp;
	for (auto& points : gm->MonsterSpawnPoints) {
		m_tmp = objf::CreateObj<Monster>("Monster");
		m_tmp->SetPos(points.x, points.y);
		m_tmp->SetThisCharacterOnTile(points.x, points.y);
	}
}
void InGameScene::SceneReset() {
	GameManager* gm = GameManager::getinstance();
	gm->map->GetMap().clear();
	gm->PF->ResetPath(gm->path);
	delete(gm->map);
	delete(gm->PF);
	delete(gm->path);
	gm->MonsterSpawnPoints.clear();

	objCol.clear();
}

InGameScene::~InGameScene() {
	objCol.clear();
}