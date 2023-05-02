#pragma once
#include<iostream>
#include<vector>
#include"Object.h"

class Object;

class GameManager
{
public:
	std::vector<Object*> objCol;
	SDL_Renderer* g_renderer;
	bool g_flag;

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
	GameManager() {}
	~GameManager();

	static GameManager* instance;
};
