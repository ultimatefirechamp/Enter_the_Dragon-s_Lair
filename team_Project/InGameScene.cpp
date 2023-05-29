#include "stdafx.h"
#include "InGameScene.h"

void InGameScene::InitScene() {
	GameManager* gm = GameManager::getinstance();
	gm->InitMap();
	gm->LoadMap("./resource/Test.txt");
	gm->map->SetTile();
	objf::CreateObj<Player>("Player");
}
InGameScene::~InGameScene() {
	objCol.clear();
}