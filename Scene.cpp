#include "stdafx.h"
#include "Scene.h"



Intro::Intro() {

}
void Intro::InitScene() {
	objCol.push_back(objf::CreateObj<BackGround>("BackGround"));
}
void Picture::Render() {
	GameManager* gm = GameManager::getinstance();
	SDL_SetRenderDrawColor(gm->g_renderer, 0, 0, 0, 0);

	SDL_Rect tmp;
	tmp = { trs->x, trs->y, trs->w,trs->h };
	SDL_RenderCopy(gm->g_renderer, sprite_->textr, &sprite_->sr, &tmp);
}

void BackGround::Update() {
	if (Iflag) {
		return;
	}
	if (i < 255) {
		SDL_SetTextureAlphaMod(getSprite()->textr, i);
		i += 3;
	}
	else if (i >= 255) {
		SDL_SetTextureAlphaMod(getSprite()->textr, 255);
		//create Next Object
		objf::CreateObj<TitleLogo>("TitleLogo");
		objf::CreateObj<CharacterTitle>("CharacterTitle");
		objf::CreateObj<StartButton>("StartButton");
		Iflag = true;
	}
}

void TitleLogo::Update() {
	if (Iflag) {
		return;
	}
	if (trs->x > 0) {
		trs->x -= 30;
	}
	else if (trs->x <= 0) {
		trs->x = 0;
		Iflag = true;
	}
}
void CharacterTitle::Update() {
	if (Iflag) {
		return;
	}
	if (trs->x < 0) {
		trs->x += 35;
	}
	else if (trs->x >= 0) {
		trs->x = 0;
		Iflag = true;
	}
}
void StartButton::Update() {
	GameManager* gm = GameManager::getinstance();
	if (Iflag) {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				gm->g_flag = false;
				//g_flag_running = false
				break;
			case SDL_MOUSEBUTTONDOWN:
				
				break;
			}
		}
	}
	else if (trs->x > 0) {
		trs->x -= 45;
	}
	else if (trs->x <= 0) {
		trs->x = 0;
		Iflag = true;
	}
}