#include "Player.h"
#include<iostream>
Player::~Player() {
	delete(trs);
	delete(sprite_);
	delete(input_);

}

void Player::Render() {
	SDL_RenderCopy(GameManager::getinstance()->g_renderer, sprite_->textr, &sprite_->sr, &trs->tr);
}