#pragma once
#include"Game.h"
#include"Object.h"
#include"stdafx.h"


class Object;
class Map;
class PathAlgorithm;
class Path;

class GameManager
{
public:
	std::vector<Object*> objCol;
	SDL_Renderer* g_renderer;
	Map* map;
	PathAlgorithm* PF;
	Path* path;

	bool g_flag;
	bool P_Turn;
	int p_x, p_y;

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
private:
	GameManager() {
		p_x = 0;
		p_y = 0;
		P_Turn = true;
	}
	~GameManager();

	static GameManager* instance;
};
