#include "stdafx.h"
#include "Scene.h"


// 인트로
Intro::Intro() {

}
void Intro::InitScene() {
	objCol.push_back(objf::CreateObj<IntroBackGround>("IntroBackGround"));
}
void Intro::SceneReset() {
	objCol.clear();
}
void Picture::Render() {
	GameManager* gm = GameManager::getinstance();
	SDL_SetRenderDrawColor(gm->g_renderer, 0, 0, 0, 0);

	SDL_Rect tmp;
	tmp = { trs->x, trs->y, trs->w,trs->h };
	SDL_RenderCopy(gm->g_renderer, sprite_->textr, &sprite_->sr, &tmp);
}

void IntroBackGround::Update() {
	if (Iflag) {
		return;
	}
	if (i < 255) {
		SDL_SetTextureAlphaMod(getSprite()->textr, i);
		i += 3;
	}
	else if (i >= 255) {
		i = 255;
		SDL_SetTextureAlphaMod(getSprite()->textr, 255);
		//create Next Object
		objf::CreateObj<TitleLogo>("SubTitleLogo");
		objf::CreateObj<SubTitleLogo>("TitleLogo");
		objf::CreateObj<CharacterTitle>("CharacterTitle");
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
void SubTitleLogo::Update() {
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
		trs->x += 20;
	}
	else if (trs->x >= 0) {
		trs->x = 0;
		objf::CreateObj<StartButton>("StartButton");
		objf::CreateObj<ExitButton>("ExitButton");
		Iflag = true;
	}
}
void StartButton::Update() {
	GameManager* gm = GameManager::getinstance();
	if (Iflag) {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				int x = event.button.x;
				int y = event.button.y;
				if (x > trs->x &&
					y > trs->y &&
					x < trs->x + trs->w &&
					y < trs->y + trs->h
					) {
					gm->Scenes[gm->CurrentPhase]->SceneReset();
					gm->objCol.clear();
					gm->CurrentPhase = INGAME;
					gm->Scenes[gm->CurrentPhase]->InitScene();
					break;
				}
			}
		}
	}
	else if (trs->x > 885) {
		trs->x -= 20;
	}
	else if (trs->x <= 885) {
		trs->x = 885;
		Iflag = true;
	}
}
void ExitButton::Update() {
	GameManager* gm = GameManager::getinstance();
	if (Iflag) {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				gm->g_flag = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				int x = event.button.x;
				int y = event.button.y;
				if (x > trs->x &&
					y > trs->y &&
					x < trs->x + trs->w &&
					y < trs->y + trs->h
					) {
					gm->g_flag = false;
					break;
				}
			}
		}
	}
	else if (trs->x > 965) {
		trs->x -= 15;
	}
	else if (trs->x <= 965) {
		trs->x = 965;
		Iflag = true;
	}
}

// 엔딩
Ending::Ending() {

}

void Ending::InitScene() {
	objCol.push_back(objf::CreateObj<EndingBackGround>("EndingBackGround"));
}

void Ending::SceneReset() {
	objCol.clear();
}

void EndingBackGround::Update() {
	GameManager* gm = GameManager::getinstance();
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			gm->CurrentPhase = INTRO;
			break;
		}
	}
}

// 처음 킬때 나오는 스토리
IntroStory::IntroStory() {

}

void IntroStory::InitScene(){
	objCol.push_back(objf::CreateObj<StoryScene>("StoryScene"));
}

void IntroStory::SceneReset() {
	objCol.clear();
}

void StoryScene::Update() {
	GameManager* gm = GameManager::getinstance();
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (i == 10) {
					gm->CurrentPhase = INTRO;
			}
			else {
				i += 1;
				ChangeScene(scene[i]);
			}
			break;
		}
	}
}