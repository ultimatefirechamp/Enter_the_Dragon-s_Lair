#pragma once
#include"Game.h"
#include"Object.h"
#include"stdafx.h"
#include"SoundManager.h"

class Object;
class Map;
class PathAlgorithm;
class Path;
class SoundManager;
class Scene;
class UI;

struct coordinate {
	int x, y;
};
class GameManager
{
public:
	std::vector<Object*> objCol;
	std::vector<Scene*> Scenes;

	UI* ui_;
	SDL_Renderer* g_renderer;
	Map* map;
	PathAlgorithm* PF;
	Path* path;
	SoundManager* sm;

	bool g_flag;
	bool P_Turn;
	int p_x, p_y;
	int SpawnPoint_x, SpawnPoint_y;


	void InitMap();

	static GameManager* getinstance() {
		if (instance == NULL) {
			instance = new GameManager();
		}
		return instance;
	}

	void PathFind(int x, int y, int x2, int y2);
	void HandleEvent();
	void Update();
	void Render();
	void TestHwakIn();
	void InitScenes();
	void LoadMap(const char* path);

	std::vector<coordinate> MonsterSpawnPoints;
	int CurrentPhase;
private:
	GameManager();
	~GameManager();

	static GameManager* instance;
};