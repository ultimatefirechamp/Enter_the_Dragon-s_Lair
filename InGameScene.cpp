#include "stdafx.h"
#include "InGameScene.h"

void InGameScene::InitScene() {
	GameManager* gm = GameManager::getinstance();
	gm->InitMap();
	
}