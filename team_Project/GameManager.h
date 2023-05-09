#pragma once
#include"Game.h"
#include"Object.h"

class Object;

class GameManager
{
public:
	std::vector<Object*> objCol;
	SDL_Renderer* g_renderer;
	bool g_flag;
	int p_x, p_y;

	static GameManager* getinstance() {
		if (instance == NULL) {
			instance = new GameManager();
		}
		return instance;
	}
	void HandleEvent();
	void Update();
	void Render();

private:
	GameManager() {
		p_x = 0;
		p_y = 0;
	}
	~GameManager();

	static GameManager* instance;
};
