#include"Components.h"
#include"SDL.h"

void Component::setOwner(Object* own) {
	m_Owner = own;
}
void InputComponent::HandleEvent() {
	GameManager* gm = GameManager::getinstance();
	SDL_Event event;
	transform_ = m_Owner->GetComponent<transform>("transform");
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameManager::getinstance()->g_flag = false;
			//g_flag_running = false
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_RIGHT) {
				transform_->x += 100;
			}
			else if (event.key.keysym.sym == SDLK_UP) {
				transform_->y -= 100;
			}
			else if (event.key.keysym.sym == SDLK_DOWN) {
				transform_->y += 100;
			}
			else if (event.key.keysym.sym == SDLK_LEFT) {
				transform_->x -= 100;
			}
			gm->p_x = transform_->x;
			gm->p_y = transform_->y;
			break;
		case SDL_KEYUP:
			break;
		}
	}
}

void SpriteComponent::InitSprite(const char* file) {
	SDL_Surface* tmp;
	tmp = IMG_Load(file);
	if (textr != 0) {
		SDL_DestroyTexture(textr);
		textr = 0;
	}
	textr = SDL_CreateTextureFromSurface(GameManager::getinstance()->g_renderer, tmp);
	SDL_FreeSurface(tmp);
}

void transform::SetPos(int x, int y) {
	this->x = x;
	this->y = y;
}
void transform::SetSize(int w, int h) {
	this->w = w;
	this->h = h;
}
SDL_Rect transform::GetRect() {
	return { this->x,this->y,this->w,this->h };
}


void SpriteComponent::SetSpriteRect(int x, int y, int w, int h) {
	sr.x = x;
	sr.y = y;
	sr.w = w;
	sr.h = h;
}
void SpriteComponent::Render() {
	SDL_Rect tmp;
	GameManager* gm = GameManager::getinstance();
	transform* t_tr = m_Owner->GetComponent<transform>("transform");
	tmp = { t_tr->x - gm->p_x + 300 - (t_tr->w / 2),
			t_tr->y - gm->p_y + 300 - (t_tr->h / 2),
			t_tr->w,t_tr->h };
	SDL_RenderCopy(gm->g_renderer, textr, &sr, &tmp);
}