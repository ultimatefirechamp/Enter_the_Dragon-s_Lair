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
	gm->ui_ = objf::CreateObj<UI>("UI");
	int x, y;
	x = 10;
	y = 10;
	tmp->GetTrans()->SetPos(x, y);
	gm->map->GetMap()[tmp->GetTrans()->x]->tiles[tmp->GetTrans()->y]->onCharacter = tmp;
	tmp->onTile = gm->map->GetMap()[tmp->GetTrans()->x]->tiles[tmp->GetTrans()->y];
	gm->p_x = x;
	gm->p_y = y;
	Monster* m_tmp = objf::CreateObj<Monster>("Monster");
	m_tmp->SetPos(5, 5);
	m_tmp->SetThisCharacterOnTile(5, 5);
	m_tmp = objf::CreateObj<Monster>("Monster");
	m_tmp->SetPos(6, 7);
	m_tmp->SetThisCharacterOnTile(6, 7);
}

void InGameScene::SceneReset() {
	GameManager* gm = GameManager::getinstance();
	gm->map->GetMap().clear();
	gm->PF->ResetPath(gm->path);
	delete(gm->map);
	delete(gm->PF);
	delete(gm->path);
	delete(gm->ui_);
	objCol.clear();
}

InGameScene::~InGameScene() {
	objCol.clear();
}