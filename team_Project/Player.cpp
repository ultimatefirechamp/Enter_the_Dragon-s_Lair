#include"stdafx.h"
#include "Player.h"
#include<iostream>
Player::~Player() {
	delete(trs);
	delete(sprite_);
	delete(input_);

}

void Player::Render() {
	sprite_->Render();
}

void Player::GetDamaged(int damage) {
	hp -= damage;
	if (hp <= 0) {
		IsAlive = false;
		hp = 0;
	}
}

void Player::move(Tile* tile, int dir) {
	onTile->onCharacter = NULL;
	switch (dir)
	{
	default:
		break;
	case 1:
		onTile = onTile->dl;
		onTile->onCharacter = this;
		break;
	case 2:
		onTile = onTile->d;
		onTile->onCharacter = this;
		break;
	case 3:
		onTile = onTile->dr;
		onTile->onCharacter = this;
		break;
	case 4:
		onTile = onTile->l;
		onTile->onCharacter = this;
		break;
	case 5:
		onTile = onTile;
		onTile->onCharacter = this;
		break;
	case 6:
		onTile = onTile->r;
		onTile->onCharacter = this;
		break;
	case 7:
		onTile = onTile->ul;
		onTile->onCharacter = this;
		break;
	case 8:
		onTile = onTile->u;
		onTile->onCharacter = this;
		break;
	case 9:
		onTile = onTile->ur;
		onTile->onCharacter = this;
		break;
	}
}

void Player::Attack(Character* monster) {
	monster->GetDamaged(10);
}

void Player::CheckIsThereEnemy() {
	if (onTile->r->onCharacter == NULL) {
		std::cout << "there is no enemy on your right tile\n";
	}
	else {
		std::cout << "there is a Character on your right tile\n";
	}
	GameManager::getinstance()->P_Turn = false;
}




void Player::HandleEvents() {
	GameManager* gm = GameManager::getinstance();
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gm->g_flag = false;
			//g_flag_running = false
			break;
		case SDL_KEYDOWN:
			if (SkillState != 0) {
				switch (SkillState)
				{
				case 1:
					if (event.key.keysym.sym == SDLK_KP_6) {

					}
				default:
					break;
				}
			}
			if (event.key.keysym.sym == SDLK_KP_6) {
				if (onTile->r->onCharacter == NULL && onTile->r->IsWalkable) {//if there is no Character
					trs->x += 1;
					move(onTile, 6);
				}
				else if (onTile->r->onCharacter != NULL) {
					onTile->r->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_5) {
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_8) {
				if (onTile->u->onCharacter == NULL && onTile->u->IsWalkable) {//if there is no Character
					trs->y -= 1;
					move(onTile, 8);
				}
				else if(onTile->u->onCharacter!=NULL){
					onTile->u->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_2) {
				if (onTile->d->onCharacter == NULL && onTile->d->IsWalkable) {
					trs->y += 1;
					move(onTile, 2);
				}
				else if (onTile->d->onCharacter != NULL) {
					onTile->d->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_4) {
				if (onTile->l->onCharacter == NULL && onTile->l->IsWalkable) {
					trs->x -= 1;
					move(onTile, 4);
				}
				else if (onTile->l->onCharacter != NULL) {
					onTile->l->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_1) {
				if (onTile->dl->onCharacter == NULL && onTile->dl->IsWalkable) {
					trs->x -= 1;
					trs->y += 1;
					move(onTile, 1);
				}
				else if (onTile->dl->onCharacter != NULL) {
					onTile->dl->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_3) {
				if (onTile->dr->onCharacter == NULL && onTile->dr->IsWalkable) {
					trs->x += 1;
					trs->y += 1;
					move(onTile, 3);
				}
				else if (onTile->dr->onCharacter != NULL) {
					onTile->dr->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_7) {
				if (onTile->ul->onCharacter == NULL && onTile->ul->IsWalkable) {
					trs->x -= 1;
					trs->y -= 1;
					move(onTile, 7);
				}
				else if (onTile->ul->onCharacter != NULL) {
					onTile->ul->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_9) {
				if (onTile->ur->onCharacter == NULL && onTile->ur->IsWalkable) {
					trs->x += 1;
					trs->y -= 1;
					move(onTile, 9);
				}
				else if (onTile->ur->onCharacter != NULL) {
					onTile->ur->onCharacter->GetDamaged(10);
				}
				gm->P_Turn = false;
			}
			gm->p_x = trs->x;
			gm->p_y = trs->y;
			if (SpriteState) {
				SpriteState = 0;
				sprite_->SetSpriteRect(24, 24, 24, 24);
			}
			else {
				SpriteState = 1;
				sprite_->SetSpriteRect(0, 24, 24, 24);
			}
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_RIGHT) {
				CheckIsThereEnemy();
			}
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		}

	}
}