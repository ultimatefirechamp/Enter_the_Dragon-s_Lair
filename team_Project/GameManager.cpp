#include"stdafx.h"
#include "GameManager.h"
#include<Windows.h>
GameManager* GameManager::instance = NULL;

GameManager::~GameManager() {
	SDL_DestroyRenderer(g_renderer);
	delete(instance);
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