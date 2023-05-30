#pragma once
#include "Object.h"

class Object;

class Scene
{
public:
	std::vector<Object*> objCol;
	virtual void InitScene() = 0;
	virtual void SceneReset() = 0;
};

// 인트로
class Intro : public Scene {
public:
	Intro();
	virtual void InitScene();
	virtual void SceneReset();
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

class IntroBackGround : public Picture {
public:
	IntroBackGround(std::string name) : Picture(name) {
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

// 엔딩
class Ending : public Scene {
public:
	Ending();
	virtual void InitScene();
	virtual void SceneReset();
};

class EndingBackGround : public Picture {
public:
	EndingBackGround(std::string name) : Picture(name) {
		getSprite()->InitSprite("./resource/Winning.png");
		getSprite()->SetSpriteRect(0, 0, 320, 180);
		trs = objf::CreateObj<transform>("transform");
		addComponent(trs);
		trs->SetPos(0, 0);
		trs->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	void Update();
};

// 처음 킬때 나오는 스토리
class IntroStory : public Scene {
public:
	IntroStory();
	virtual void InitScene();
	virtual void SceneReset();
};

class StoryScene : public Picture {
public:
	StoryScene(std::string name) : Picture(name) {
		scene[0] = "./resource/intro_story/int1.png";
		scene[1] = "./resource/intro_story/int2.png";
		scene[2] = "./resource/intro_story/int3.png";
		scene[3] = "./resource/intro_story/int4.png";
		scene[4] = "./resource/intro_story/int5.png";
		scene[5] = "./resource/intro_story/int6.png";
		scene[6] = "./resource/intro_story/int7.png";
		scene[7] = "./resource/intro_story/int8.png";
		scene[8] = "./resource/intro_story/int9.png";
		scene[9] = "./resource/intro_story/int10.png";
		scene[10] = "./resource/intro_story/int11.png";


		ChangeScene(scene[i]);
	}

	void ChangeScene(std::string scene) {
		getSprite()->InitSprite(scene.c_str());
		getSprite()->SetSpriteRect(0, 0, 640, 360);
		trs = objf::CreateObj<transform>("transform");
		addComponent(trs);
		trs->SetPos(0, 0);
		trs->SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	void Update();

private:
	int i = 0;
	std::string scene[11];
};