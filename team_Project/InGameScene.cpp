#include "stdafx.h"
#include "InGameScene.h"

void InGameScene::InitScene() {
	GameManager* gm = GameManager::getinstance();
	gm->InitMap();
	gm->map->SetTile();
	objf::CreateObj<Player>("Player");
}