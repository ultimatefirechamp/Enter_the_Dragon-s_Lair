#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"SDL_mixer.h"
#include<fstream>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define INTRO 0
#define INGAME 1
#define ENDING 2


enum States
{
	IDLE,
	PUNCH_READY,
	PUNCH,
	KICK
};
enum Skills {
	ONE_INCH_PUNCH,
	DRAGON_KICK,
	ONE_WILD_WIND
};

namespace objf {
	template<class tObj>
	tObj* CreateObj(std::string objName) {
		tObj* obj = new tObj(objName);
		return obj;
	}
	template<class tComp>
	tComp* CreateComp(std::string compName) {
		tComp* cmp = new tComp(compName);
		return cmp;
	}
}