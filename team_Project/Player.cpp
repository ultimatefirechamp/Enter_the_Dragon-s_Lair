#include"stdafx.h"
#include "Player.h"
#include<iostream>
Player::~Player() {
	delete(trs);
	delete(sprite_);
	delete(input_);

}
void Player::SetMotion(States st) {
	switch (st)
	{
	case IDLE:
		if (sprite_->sr.x == 0)
			sprite_->SetSpriteRect(24, 96, 24, 24);
		else
			sprite_->SetSpriteRect(0,96,24,24);
		break;
	case PUNCH_READY:
		sprite_->SetSpriteRect(72, 96, 24, 24);
		break;
	case PUNCH:
		sprite_->SetSpriteRect(144, 96, 24, 24);
		//sprite_->SetSpriteRect();
		break;
	case KICK:
		sprite_->SetSpriteRect(168, 96, 24, 24);
		//sprite_->SetSpriteRect();
		break;
	default:
		break;
	}
}	

void Player::Skill(SDL_Event event) {
	Tile* tmp = NULL;
	GameManager* gm = GameManager::getinstance();
	int dir;
	switch (SkillState)
	{
	case ONE_INCH_PUNCH:
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_KP_6:
			tmp = onTile->r;
			dir = 6;
			break;
		case SDLK_KP_4:
			tmp = onTile->l;
			dir = 4;
			break;
		case SDLK_KP_2:
			tmp = onTile->d;
			dir = 2;
			break;
		case SDLK_KP_8:
			tmp = onTile->u;
			dir = 8;
			break;
		case SDLK_KP_7:
			tmp = onTile->ul;
			dir = 7;
			break;
		case SDLK_KP_9:
			tmp = onTile->ur;
			dir = 9;
			break;
		case SDLK_KP_1:
			tmp = onTile->dl;
			dir = 1;
			break;
		case SDLK_KP_3:
			tmp = onTile->dr;
			dir = 3;
			break;
		case SDLK_KP_5:
			SKillOn = false;
			SpriteState = IDLE;
			dir = 5;
			break;
		default:
			break;
		}
		if (dir != 5 && tmp->onCharacter != NULL) {
			gm->sm->player_atk_sound();
			tmp->onCharacter->GetDamaged(40);
			SpriteState = PUNCH;
			SKillOn = false;
		}
		else {
			SpriteState = IDLE;
			move(onTile, dir);
			SKillOn = false;
		}

	}
		break;

	case DRAGON_KICK:
		break;
	case ONE_WILD_WIND:
		break;
	default:
		break;
	}
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
	trs->SetPos(onTile->mapX, onTile->mapY);
}

void Player::Attack(Character* monster) {
	GameManager::getinstance()->sm->player_atk_sound();
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
			if (SKillOn) {
				Skill(event);
			}
			else if (event.key.keysym.sym == SDLK_KP_6) {
				if (onTile->r->onCharacter == NULL && onTile->r->IsWalkable) {//if there is no Character
					SpriteState = IDLE;
					move(onTile, 6);
				}
				else if (onTile->r->onCharacter != NULL) {
					Attack(onTile->r->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_5) {
				SpriteState = IDLE;
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_8) {
				if (onTile->u->onCharacter == NULL && onTile->u->IsWalkable) {//if there is no Character
					SpriteState = IDLE;
					move(onTile, 8);
				}
				else if (onTile->u->onCharacter != NULL) {
					Attack(onTile->u->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_2) {
				if (onTile->d->onCharacter == NULL && onTile->d->IsWalkable) {
					SpriteState = IDLE;
					move(onTile, 2);
				}
				else if (onTile->d->onCharacter != NULL) {
					Attack(onTile->d->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_4) {
				if (onTile->l->onCharacter == NULL && onTile->l->IsWalkable) {
					SpriteState = IDLE;
					move(onTile, 4);
				}
				else if (onTile->l->onCharacter != NULL) {
					Attack(onTile->l->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_1) {
				if (onTile->dl->onCharacter == NULL && onTile->dl->IsWalkable) {
					SpriteState = IDLE;
					move(onTile, 1);
				}
				else if (onTile->dl->onCharacter != NULL) {
					Attack(onTile->dl->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_3) {
				if (onTile->dr->onCharacter == NULL && onTile->dr->IsWalkable) {
					
					SpriteState = IDLE;
					move(onTile, 3);
				}
				else if (onTile->dr->onCharacter != NULL) {
					Attack(onTile->dr->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_7) {
				if (onTile->ul->onCharacter == NULL && onTile->ul->IsWalkable) {
					
					SpriteState = IDLE;
					move(onTile, 7);
				}
				else if (onTile->ul->onCharacter != NULL) {
					Attack(onTile->ul->onCharacter);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_KP_9) {
				if (onTile->ur->onCharacter == NULL && onTile->ur->IsWalkable) {
					move(onTile, 9);
					SpriteState = IDLE;
				}
				else if (onTile->ur->onCharacter != NULL) {
					Attack(onTile->ur->onCharacter);
				}
				gm->P_Turn = false;
			}
			gm->p_x = trs->x;
			gm->p_y = trs->y;
			SetMotion(SpriteState);
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_RIGHT) {
				SkillState = ONE_INCH_PUNCH;
				SpriteState = PUNCH_READY;
				SetMotion(SpriteState);
				SKillOn = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		}
		
	}
}