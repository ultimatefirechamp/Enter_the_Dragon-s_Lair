#include"stdafx.h"
#include "GameManager.h"
#include<Windows.h>

GameManager* GameManager::instance = NULL;

GameManager::GameManager() {
	p_x = 0;
	p_y = 0;
	P_Turn = true;
	CurrentPhase = 0;
	Scenes.push_back(new IntroStory());
	Scenes.push_back(new Intro());
	Scenes.push_back(new InGameScene());
	Scenes.push_back(new Ending());
	sm = new SoundManager();
	
}

GameManager::~GameManager() {
	SDL_DestroyRenderer(g_renderer);
	delete(instance);
}
void GameManager::InitScenes() {
	/*for (auto& scene : Scenes) {
		this->objCol = scene->objCol;
		scene->InitScene();
		scene->objCol = this->objCol;
	}*/
	CurrentPhase = INTRO;
	Scenes[CurrentPhase]->InitScene();
	this->objCol = Scenes[CurrentPhase]->objCol;
}

void GameManager::LoadMap(const char* path) {
	int row = 13;
	int col = 13;
	std::ifstream mapFile;
	mapFile.open(path);
	for (int i = 0; i < map->GetMap().size(); i++) {
		map->GetMap()[i]->tiles.clear();
	}
	map->GetMap().clear();

	mapFile >> row >> col;
	char tmp;
	for (int r = 0; r < row; r++) {
		map->GetMap().push_back(new TileRow());
		for (int c = 0; c < col; c++) {
			Tile* tmp_t = NULL;
			mapFile >> tmp;
			switch (tmp)
			{
			case '0':
				tmp_t = new AIR("AIR", r, c);
				break;
			case '1':
				tmp_t = new Wall("Wall", r, c);
				break;
			case '2':
				tmp_t = new Floor("Floor", r, c);
				break;
			case '3':
				SpawnPoint_x = r;
				SpawnPoint_y = c;
				tmp_t = new Floor("Floor", r, c);
				break;
			case '4':
				tmp_t = new Floor("Floor", r, c);
				coordinate tmp_c = coordinate { r,c };
				MonsterSpawnPoints.push_back(tmp_c);
			default:
				break;
			}

			tmp_t->GetTrans()->SetPos(r, c);
			map->GetMap()[r]->tiles.push_back(tmp_t);
		}
	}

	map->SetTile();
}

void GameManager::InitMap() {
	map = new Map();
	PF = new PathAlgorithm();
	path = new Path();
	/*for (int i = 0; i < 10; i++) {
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
			tmp->GetTrans()->SetPos(i, j);
			map->GetMap()[i]->tiles.push_back(tmp);
		}
	}*/
}

void GameManager::PathFind(int x, int y, int x2, int y2) {
	path->positions.clear();
	path->open.clear();
	path->open.push_back(map->GetMap()[x]->tiles[y]);
	path->start = map->GetMap()[x]->tiles[y];
	path->start->open = true;

	path->end = map->GetMap()[x2]->tiles[y2];

	PF->CalculatePath(path);
	path->positions;

}

void GameManager::TestHwakIn() {
	for (Tile* tile : path->positions) {
		std::cout << "(" << tile->GetTrans()->x << ", " << tile->GetTrans()->y << ")\n";
	}
	std::cout << std::endl;
}



void GameManager::HandleEvent() {}

void GameManager::Update() {
	for (auto& i : objCol) {
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
		if (CurrentPhase == INGAME) {
			ui_->Render();
		}
	}

	SDL_RenderPresent(g_renderer);
}
