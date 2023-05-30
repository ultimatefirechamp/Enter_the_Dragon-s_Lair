#include"stdafx.h"
#include "Player.h"
#include<iostream>
Player::~Player() {
	delete(trs);
	delete(sprite_);
	delete(input_);

}


void EndingChanger::Update() {
	GameManager* gm = GameManager::getinstance();
	gm->Scenes[gm->CurrentPhase]->SceneReset();
	gm->CurrentPhase = ENDING;
	gm->Scenes[gm->CurrentPhase]->InitScene();
	gm->objCol.clear();
	gm->objCol = gm->Scenes[gm->CurrentPhase]->objCol;
	return;
}

void Player::move(Tile* tar) {
	onTile->onCharacter = NULL;
	onTile = tar;
	onTile->onCharacter = this;
	trs->SetPos(onTile->mapX, onTile->mapY);
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
	case ST_OF_H:
		sprite_->SetSpriteRect(192, 96, 24, 24);
		break;
	default:
		break;
	}
}	

void Player::Skill(SDL_Event event) {
	Tile* tmp = NULL;
	Tile* tmp2 = NULL;
	Tile* tmp3 = NULL;
	GameManager* gm = GameManager::getinstance();
	int dir = -1;
	switch (SkillState)
	{
	case ONE_INCH_PUNCH:
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			tmp = onTile->r;
			dir = 6;
			break;
		case SDLK_a:
			tmp = onTile->l;
			dir = 4;
			break;
		case SDLK_x:
			tmp = onTile->d;
			dir = 2;
			break;
		case SDLK_w:
			tmp = onTile->u;
			dir = 8;
			break;
		case SDLK_q:
			tmp = onTile->ul;
			dir = 7;
			break;
		case SDLK_e:
			tmp = onTile->ur;
			dir = 9;
			break;
		case SDLK_z:
			tmp = onTile->dl;
			dir = 1;
			break;
		case SDLK_c:
			tmp = onTile->dr;
			dir = 3;
			break;
		case SDLK_s:
			dir = 5;
			tmp = onTile;
			break;
		default:
			break;
		}
		if (tmp == NULL) {
			return;
		}
		if (dir != 5 && tmp->onCharacter != NULL) {
			if (stamina < 20) {
				SKillOn = false;
				SpriteState = IDLE;
				return;
			}
			stamina -= 20;
			stbar->set_st(stamina);
			gm->sm->player_atk_sound();
			Attack(tmp->onCharacter, 40);
			SpriteState = PUNCH;
			SKillOn = false;
			gm->P_Turn = false;
		}
		else if(dir != -1){
			SpriteState = IDLE;
			move(onTile, dir);
			SKillOn = false;
			gm->P_Turn = false;
		}

	}
		break;

	case DRAGON_KICK:
		break;
	case STATUE_OF_HEAVEN:

		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			tmp = onTile->r;
			dir = 6;
			break;
		case SDLK_a:
			tmp = onTile->l;
			dir = 4;
			break;
		case SDLK_x:
			tmp = onTile->d;
			dir = 2;
			break;
		case SDLK_w:
			tmp = onTile->u;
			dir = 8;
			break;
		case SDLK_q:
			tmp = onTile->ul;
			dir = 7;
			break;
		case SDLK_e:
			tmp = onTile->ur;
			dir = 9;
			break;
		case SDLK_z:
			tmp = onTile->dl;
			dir = 1;
			break;
		case SDLK_c:
			tmp = onTile->dr;
			dir = 3;
			break;
		case SDLK_s:
			tmp = onTile;
			dir = 5;
			break;
		default:
			break;
		}
		if (tmp == NULL) {
			return;
		}
		if (!tmp->IsWalkable) {
			SKillOn = false;
			SpriteState = IDLE;
			gm->P_Turn = false;
			return;
		}
		if (dir != 5 && tmp->onCharacter != NULL) {
			if (stamina < 40) {
				SKillOn = false;
				SpriteState = IDLE;
				return;
			}
			stamina -= 40;
			stbar->set_st(stamina);
			gm->sm->player_atk_sound();
			if (onTile->u->onCharacter != NULL)
				Attack(onTile->u->onCharacter,15);
			if (onTile->d->onCharacter != NULL)
				Attack(onTile->d->onCharacter, 15);
			if (onTile->r->onCharacter != NULL)
				Attack(onTile->r->onCharacter, 15);
			if (onTile->l->onCharacter != NULL)
				Attack(onTile->l->onCharacter, 15);
			if (onTile->ul->onCharacter != NULL)
				Attack(onTile->ul->onCharacter, 15);
			if (onTile->ur->onCharacter != NULL)
				Attack(onTile->ur->onCharacter, 15);
			if (onTile->dl->onCharacter != NULL)
				Attack(onTile->dl->onCharacter, 15);
			if (onTile->dr->onCharacter != NULL)
				Attack(onTile->dr->onCharacter, 15);
			if (tmp->onCharacter != NULL)
				Attack(tmp->onCharacter, 15);
			SpriteState = ST_OF_H;

			SKillOn = false;
			gm->P_Turn = false;
		}
		else if (dir != -1) {
			SpriteState = IDLE;
			move(onTile, dir);
			SKillOn = false;
			gm->P_Turn = false;
		}


		break;
	case ONE_WILD_WIND:
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			tmp = onTile->r;
			tmp2 = onTile->r->r;
			dir = 6;
			break;
		case SDLK_a:
			tmp = onTile->l;
			tmp2 = onTile->l->l;
			dir = 4;
			break;
		case SDLK_x:
			tmp = onTile->d;
			tmp2 = onTile->d->d;
			dir = 2;
			break;
		case SDLK_w:
			tmp = onTile->u;
			tmp2 = onTile->u->u;
			dir = 8;
			break;
		case SDLK_q:
			tmp = onTile->ul;
			tmp2 = onTile->ul->ul;
			dir = 7;
			break;
		case SDLK_e:
			tmp = onTile->ur;
			tmp2 = onTile->ur->ur;
			dir = 9;
			break;
		case SDLK_z:
			tmp = onTile->dl;
			tmp2 = onTile->dl->dl;
			dir = 1;
			break;
		case SDLK_c:
			tmp = onTile->dr;
			tmp2 = onTile->dr->dr;
			dir = 3;
			break;
		case SDLK_s:
			dir = 5;
			break;
		default:
			break;
		}
		if (tmp == NULL) {
			return;
		}
		if (dir != 5 && tmp->onCharacter != NULL) {
			if (stamina < 10) {
				SKillOn = false;
				SpriteState = IDLE;
				return;
			}
			stamina -= 10;
			stbar->set_st(stamina);
			gm->sm->player_atk_sound();
			Attack(tmp->onCharacter,15);
			SpriteState = PUNCH;
			SKillOn = false;
			gm->P_Turn = false;
		}
		else if (dir != 5 && tmp->onCharacter == NULL) {
			move(onTile, dir);
			if (tmp2->onCharacter != NULL) {
				if (stamina < 10) {
					SKillOn = false;
					SpriteState = IDLE;
					return;
				}
				stamina -= 10;
				stbar->set_st(stamina);
				gm->sm->player_atk_sound();
				tmp2->onCharacter->GetDamaged(40);
				SpriteState = PUNCH;
				SKillOn = false;
				gm->P_Turn = false;
			}
			else {
				SKillOn = false;
				SpriteState = IDLE;
				gm->P_Turn = false;
			}
		}
		else if (dir != -1) { // dir == 5
			SpriteState = IDLE;
			move(onTile, dir);
			SKillOn = false;
			gm->P_Turn = false;

		}
		break;
	case WALL_RUN:
		WallRun(event, gm);
	default:
		break;
	}
}
void Player::WallRun(SDL_Event event, GameManager* &gm) {
	Tile* tmp = NULL;
	Tile* tmp2 = NULL;
	int dir = -1;
	switch (event.key.keysym.sym)
	{
	case SDL_QUIT:
		gm->g_flag = false;
	case SDLK_d:
		dir = 4;
		tmp = onTile->r;
		tmp2 = onTile->l->l;
		break;
	case SDLK_a:
		dir = 6;
		tmp = onTile->l;
		tmp2 = onTile->r->r;
		break;
	case SDLK_x:
		dir = 8;
		tmp = onTile->d;
		tmp2 = onTile->u->u;
		break;
	case SDLK_w:
		dir = 2;
		tmp = onTile->u;
		tmp2 = onTile->d->d;
		break;
	case SDLK_q:
		dir = 3;
		tmp = onTile->ul;
		tmp2 = onTile->dr->dr;
		break;
	case SDLK_e:
		dir = 1;
		tmp = onTile->ur;
		tmp2 = onTile->dl->dl;
		break;
	case SDLK_z:
		dir = 9;
		tmp = onTile->dl;
		tmp2 = onTile->ur->ur;
		break;
	case SDLK_c:
		dir = 7;
		tmp = onTile->dr;
		tmp2 = onTile->ul->ul;
		break;
	case SDLK_s:
		dir = 5;
		tmp = onTile;
		break;
	default:
		break;
	}
	if (tmp == NULL) {
		return;
	}
	if (!tmp->IsWalkable) {
		if (tmp2->IsWalkable && tmp2->onCharacter == NULL) {
			if (stamina < 40) {
				SKillOn = false;
				SpriteState = IDLE;
				return;
			}
			stamina -= 40;
			stbar->set_st(stamina);
			move(tmp2);
			gm->sm->player_atk_sound();
			if (onTile->u->onCharacter != NULL)
				Attack(onTile->u->onCharacter,15);
			if (onTile->d->onCharacter != NULL)
				Attack(onTile->d->onCharacter, 15);
			if (onTile->r->onCharacter != NULL)
				Attack(onTile->r->onCharacter, 15);
			if (onTile->l->onCharacter != NULL)
				Attack(onTile->l->onCharacter, 15);
			if (onTile->ul->onCharacter != NULL)
				Attack(onTile->ul->onCharacter, 15);
			if (onTile->ur->onCharacter != NULL)
				Attack(onTile->ur->onCharacter, 15);
			if (onTile->dl->onCharacter != NULL)
				Attack(onTile->dl->onCharacter, 15);
			if (onTile->dr->onCharacter != NULL)
				Attack(onTile->dr->onCharacter, 15);
			SpriteState = IDLE;
			SKillOn = false;
		}
		else {
			SKillOn = false;
			gm->P_Turn = false;
			SpriteState = IDLE;
		}
	}
	else {
		move(tmp);
		SpriteState = IDLE;
		SKillOn = false;
		gm->P_Turn = false;
	}
}
void Player::Render() {
	sprite_->Render();
	hpbar->Render();
	stbar->Render();
}

bool Player::GetDamaged(int damage) {
	hp -= damage;
	hpbar->set_hp(hp);
	if (hp <= 0) {
		IsAlive = false;
		hp = 0;
		return true;
	}
	return false;
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
	if (monster->GetDamaged(20)) {
		MonsterNumber--;
		stamina += 33;
		hp += 20;
		hp = std::min(hp, max_hp);
		stamina = std::min(stamina, MaxStamina);
		hpbar->set_hp(hp);
		stbar->set_st(stamina);
	}
}
void Player::Attack(Character* monster, int dam) {
	GameManager::getinstance()->sm->player_atk_sound();
	if (monster->GetDamaged(dam)) {
		MonsterNumber--;
		stamina += 33;
		hp += 33;
		hp = std::min(hp, max_hp);
		stamina = std::min(stamina, MaxStamina);
		hpbar->set_hp(hp);
		stbar->set_st(stamina);
	}
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
		if (!gm->P_Turn) {
			gm->P_Turn = true;
			return;
		}
		switch (event.type) {
		case SDL_QUIT:
			gm->g_flag = false;
			//g_flag_running = false
			break;
		case SDL_KEYDOWN:
			if (!IsAlive) {
				return;
			}
			if (SKillOn) {
				Skill(event);
			}
			else if (event.key.keysym.sym == SDLK_d) {
				if (onTile->r->onCharacter == NULL && onTile->r->IsWalkable) {//if there is no Character
					SpriteState = IDLE;
					move(onTile, 6);
				}
				else if (onTile->r->onCharacter != NULL) {
					Attack(onTile->r->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_s) {
				SpriteState = IDLE;
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_w) {
				if (onTile->u->onCharacter == NULL && onTile->u->IsWalkable) {//if there is no Character
					SpriteState = IDLE;
					move(onTile, 8);
				}
				else if (onTile->u->onCharacter != NULL) {
					Attack(onTile->u->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_x) {
				if (onTile->d->onCharacter == NULL && onTile->d->IsWalkable) {
					SpriteState = IDLE;
					move(onTile, 2);
				}
				else if (onTile->d->onCharacter != NULL) {
					Attack(onTile->d->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_a) {
				if (onTile->l->onCharacter == NULL && onTile->l->IsWalkable) {
					SpriteState = IDLE;
					move(onTile, 4);
				}
				else if (onTile->l->onCharacter != NULL) {
					Attack(onTile->l->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_z) {
				if (onTile->dl->onCharacter == NULL && onTile->dl->IsWalkable) {
					SpriteState = IDLE;
					move(onTile, 1);
				}
				else if (onTile->dl->onCharacter != NULL) {
					Attack(onTile->dl->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_c) {
				if (onTile->dr->onCharacter == NULL && onTile->dr->IsWalkable) {
					
					SpriteState = IDLE;
					move(onTile, 3);
				}
				else if (onTile->dr->onCharacter != NULL) {
					Attack(onTile->dr->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_q) {
				if (onTile->ul->onCharacter == NULL && onTile->ul->IsWalkable) {
					
					SpriteState = IDLE;
					move(onTile, 7);
				}
				else if (onTile->ul->onCharacter != NULL) {
					Attack(onTile->ul->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_e) {
				if (onTile->ur->onCharacter == NULL && onTile->ur->IsWalkable) {
					move(onTile, 9);
					SpriteState = IDLE;
				}
				else if (onTile->ur->onCharacter != NULL) {
					Attack(onTile->ur->onCharacter);
					stamina += 10;
					stamina = std::min(stamina, MaxStamina);
				}
				gm->P_Turn = false;
			}
			else if (event.key.keysym.sym == SDLK_5) {
				this->IsAlive = false;
			}
			else if (event.key.keysym.sym == SDLK_p) {
				SkillState = ONE_WILD_WIND;
				SpriteState = PUNCH_READY;
				SetMotion(SpriteState);
				SKillOn = true;
			}
			else if (event.key.keysym.sym == SDLK_u) {
				SkillState = ONE_INCH_PUNCH;
				SpriteState = PUNCH_READY;
				SetMotion(SpriteState);
				SKillOn = true;
			}
			else if (event.key.keysym.sym == SDLK_o) {
				SkillState = STATUE_OF_HEAVEN;
				SpriteState = PUNCH_READY;
				SetMotion(SpriteState);
				SKillOn = true;
			}
			else if (event.key.keysym.sym == SDLK_i) {
				SkillState = WALL_RUN;
				SpriteState = PUNCH_READY;
				SetMotion(SpriteState);
				SKillOn = true;
			}
			else if (event.key.keysym.sym == SDLK_7) {
				MonsterNumber = 0;
			}
			gm->p_x = trs->x;
			gm->p_y = trs->y;
			stbar->set_st(stamina);
			SetMotion(SpriteState);
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		}
		
	}
}



// 게임 오버 화면
void GameOverScreen::Update() {
	if (i < 255) {
		SDL_SetTextureAlphaMod(sprite_->textr, i);
		i += 3;
	}
	else if (i >= 255) {
		SDL_SetTextureAlphaMod(sprite_->textr, 255);
	}

	GameManager* gm = GameManager::getinstance();
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					gm->Scenes[gm->CurrentPhase]->SceneReset();
					gm->CurrentPhase = INTRO;
					gm->Scenes[gm->CurrentPhase]->InitScene();
					gm->objCol = gm->Scenes[gm->CurrentPhase]->objCol;
					gm->sm->intro_music();
				}
				break;
			case SDL_MOUSEBUTTONUP:
				break;
		}
	}
}

void GameOverScreen::Render() {
	GameManager* gm = GameManager::getinstance();

	SDL_Rect tmp = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	SDL_RenderCopy(gm->g_renderer, sprite_->textr, &sprite_->sr, &tmp);
}