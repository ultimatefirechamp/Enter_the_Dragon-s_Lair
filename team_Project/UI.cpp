#include "stdafx.h"
#include "UI.h"

// UI
void UI::Update() {
}

void UI::Render() {
	GameManager* gm = GameManager::getinstance();

	SDL_Rect tmp = { 10, 635, 286, 76 };
	SDL_RenderCopy(gm->g_renderer, sprite_->textr, &sprite_->sr, &tmp);
}