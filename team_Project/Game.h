#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"SDL_mixer.h"


#include"Object.h"
#include"GameManager.h"
#include"Components.h"

namespace objf {
	template<class tObj>
	tObj* CreateObj(std::string objName) {
		tObj* obj = new tObj(objName);
		return obj;
	}
	template<class tObj>
	tObj* GetObj(std::string objName) {
		for (auto& i : GameManager::getinstance()->objCol) {
			if (i->GetName == objName) {
				return dynamic_cast<tObj*>i;
			}
		}
		return nullptr;
	}
	template<class tComp>
	tComp* CreateComp(std::string compName) {
		tComp* cmp = new tComp(compName);
		return cmp;
	}
}