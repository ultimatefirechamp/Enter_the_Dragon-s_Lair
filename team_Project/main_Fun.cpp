#include"stdafx.h"
#include<iostream>
#include"GameManager.h"
#include"SDL.h"
#include"Components.h"
#include"Player.h"
#include"Monster.h"

void InitGame() {
	GameManager::getinstance()->g_flag = true;
}
int main(int arc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("wer", 100, 100, 600, 600, 0);
	GameManager* gm = GameManager::getinstance();
	gm->g_renderer = SDL_CreateRenderer(win, -1, 0);

	objf::CreateObj<Player>("Player");
	objf::CreateObj<Monster>("Monster");
	gm->InitMap();
	InitGame();
	gm->map->SetTile();
	gm->PathFindTest();

	while (gm->g_flag) {
		gm->Update();
		gm->Render();
		SDL_Delay(33);
	}

	for (int i = 0; i < gm->objCol.size(); i++) {
		delete(gm->objCol[i]);
	}

	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}