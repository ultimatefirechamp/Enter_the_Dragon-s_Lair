#include "stdafx.h"
#include "UI.h"

// UI
void UI::Update() {
}

void UI::Render() {
	GameManager* gm = GameManager::getinstance();

	SDL_Rect tmp = { 1000, 0, 159, 42 };
	SDL_RenderCopy(gm->g_renderer, sprite_->textr, &sprite_->sr, &tmp);
}