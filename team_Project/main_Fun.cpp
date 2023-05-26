#include"stdafx.h"
#include<iostream>
#include"GameManager.h"
#include"SDL.h"
#include"Components.h"
#include"Player.h"
#include"Monster.h"

Uint32 g_last_time_ms;

void InitGame() {
	GameManager* gm = GameManager::getinstance();
	GameManager::getinstance()->g_flag = true;
	gm->InitScenes();
}
int main(int arc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("wer", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	GameManager* gm = GameManager::getinstance();
	gm->g_renderer = SDL_CreateRenderer(win, -1, 0);

	//gm->InitMap();
	InitGame();
	//gm->map->SetTile();
	//gm->PathFind(1, 8, 8, 1);
	//gm->TestHwakIn();

	/*Monster* mn;
	objf::CreateObj<Player>("Player");
	mn = objf::CreateObj<Monster>("Monster");
	mn->SetPos(5, 1);
	mn->SetThisCharacterOnTile(5, 1);
	mn = objf::CreateObj<Monster>("Monster");
	mn->SetPos(3, 3);
	mn->SetThisCharacterOnTile(3, 3);*/

	gm->sm->intro_music();
	g_last_time_ms = SDL_GetTicks();

	while (gm->g_flag) {
		Uint32 cur_time_ms = SDL_GetTicks();
		if (cur_time_ms - g_last_time_ms < 33)
			continue;
		gm->Update();
		gm->Render();

		g_last_time_ms = cur_time_ms;
	}

	for (int i = 0; i < gm->objCol.size(); i++) {
		delete(gm->objCol[i]);
	}

	SDL_DestroyWindow(win);


	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	return 0;
}