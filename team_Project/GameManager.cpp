#include"stdafx.h"
#include "GameManager.h"
#include<Windows.h>

GameManager* GameManager::instance = NULL;

GameManager::~GameManager() {
	SDL_DestroyRenderer(g_renderer);
	delete(instance);
}

void GameManager::InitMap() {
	map = new Map();
	PF = new PathAlgorithm();
	path = new Path();
	for (int i = 0; i < 10; i++) {
		map->GetMap().push_back(new TileRow());
		for (int j = 0; j < 10; j++) {
			Tile* tmp;
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				tmp = new Wall("Wall", i, j);
			}
			else if (i == 4) {
				if (j == 4) {
					tmp = new Floor("Floor", i, j);
				}
				else {
					tmp = new Wall("Wall", i, j);
				}
			}
			else {
				tmp = new Floor("Floor", i, j);
			}
			tmp->GetTrans()->SetPos(i * 100, j * 100);
			map->GetMap()[i]->tiles.push_back(tmp);
		}
	}
}

void GameManager::PathFindTest() {
	path->positions.clear();
	path->open.clear();
	path->open.push_back(map->GetMap()[1]->tiles[1]);
	path->start = map->GetMap()[1]->tiles[1];
	path->start->open = true;

	path->end = map->GetMap()[8]->tiles[1];
	
	PF->CalculatePath(path);
	
}



void GameManager::HandleEvent() {}

void GameManager::Update() {
	for (auto &i : objCol) {
		i->Update();
	}
	for (int i = 0; i < objCol.size(); i++) {
		if (!objCol[i]->IsOn) {
			objCol.erase(objCol.begin() + i);
			i--;
		}
	}
}
void GameManager::Render() {

	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0);
	SDL_RenderClear(g_renderer);
	for (int i = 0; i < objCol.size(); i++) {
		objCol[i]->Render();
	}

	SDL_RenderPresent(g_renderer);

}