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
#define INTRO_STORY 0
#define INTRO 1
#define INGAME 2
#define ENDING 3


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
	ONE_WILD_WIND,
	STATUE_OF_HEAVEN
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