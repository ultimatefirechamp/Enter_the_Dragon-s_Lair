#pragma once
#include "Object.h"

class Object;

class Scene
{
public:
	std::vector<Object*> objCol;
	virtual void InitScene() = 0;
};

class Intro : public Scene {
public:
	Intro();
	virtual void InitScene();
};

class Picture : public Object {
public:
	Picture(std::string name) : Object(name) {
		sprite_ = objf::CreateObj<SpriteComponent>("SpriteComponent");
		addComponent(sprite_);
	}
	virtual void Update() = 0;
	void Render();
	SpriteComponent* getSprite() { return sprite_; }
private:
	SpriteComponent* sprite_;
};

class BackGround : public Picture {
public:
	BackGround(std::string name) : Picture(name) {
		getSprite()->InitSprite("./resource/start_background.png");
		getSprite()->SetSpriteRect(0, 0, 320, 180);
		SDL_SetTextureAlphaMod(getSprite()->textr, 0);
		trs = objf::CreateObj<transform>("transform");
		addComponent(trs);
		trs->SetPos(0, 0);
		trs->SetSize(WINDOW_WIDTH,WINDOW_HEIGHT);
		Iflag = false;
	}
	void Update();
private:
	int i = 0;
	bool Iflag;
};

class TitleLogo : public Picture {
public:
	TitleLogo(std::string name) : Picture(name) {
		getSprite()->InitSprite("./resource/start_title.png");//320 180
		getSprite()->SetSpriteRect(0, 0, 320, 180);
		trs = objf::CreateObj<transform>("transform");
		addComponent(trs);
		trs->SetPos(1280, 30);
		trs->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	void Update();
private:
	bool Iflag = false;
};

class CharacterTitle : public Picture {
public:
	CharacterTitle(std::string name) : Picture(name) {
		getSprite()->InitSprite("./resource/start_character.png");
		getSprite()->SetSpriteRect(0, 0, 320, 180);
		trs = objf::CreateObj<transform>("transform");
		addComponent(trs);
		trs->SetPos(-852, 68);
		trs->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	void Update();
private:
	bool Iflag = false;
};

class StartButton : public Picture {
public:
	StartButton(std::string name) : Picture(name) {
		getSprite()->InitSprite("./resource/start_button.png");
		getSprite()->SetSpriteRect(0, 0, 320, 180);
		trs = objf::CreateObj<transform>("transform");
		addComponent(trs);
		trs->SetPos(1280, 30);
		trs->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	void Update();
private:
	bool Iflag = false;
};