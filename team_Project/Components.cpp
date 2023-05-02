#include"Components.h"
#include"SDL.h"

void Component::setOwner(Object* own) {
	m_Owner = own;
}
void InputComponent::HandleEvent() {
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
				transform_->SetPos(transform_->x + 100, transform_->y);
				transform_->x += 100;
			}
			else if (event.key.keysym.sym == SDLK_UP) {
				transform_->SetPos(transform_->x, transform_->y - 100);
				transform_->y -= 100;
			}
			else if (event.key.keysym.sym == SDLK_DOWN) {
				transform_->SetPos(transform_->x, transform_->y + 100);
				transform_->y += 100;
			}
			else if (event.key.keysym.sym == SDLK_LEFT) {
				transform_->SetPos(transform_->x - 100, transform_->y);
				transform_->x -= 100;
			}
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

