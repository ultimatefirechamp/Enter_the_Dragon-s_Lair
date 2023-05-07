#pragma once
#include"Game.h"

class Object;
class GameManager;

class Component {
protected:
	std::string name;
	Object* m_Owner;
public:
	
	void setOwner(Object* own);
	Object* getOwner() { return m_Owner; }
	
	virtual void Update() = 0;

	std::string GetName() { return name; }

	Component(std::string n) {
		name = n;
	}
	~Component() {}

};

class transform : public Component {
public:
	transform(std::string name) : Component(name) {}

	void SetPos(int x, int y);
	void SetSize(int w, int h);

	void Update() {}
	SDL_Rect GetRect();

	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
};


class InputComponent: public Component {
public:
	InputComponent(std::string name) : Component(name) {}

	void HandleEvent();

	void Update() {
		
	}
	
private:
	transform* transform_;
};

class SpriteComponent : public Component {
public:

	void InitSprite(const char* file);
	void SetSpriteRect(int x, int y, int w, int h);

	SpriteComponent(std::string name) : Component(name) {}
	
	~SpriteComponent() {
		SDL_DestroyTexture(textr);
	}

	void Update() {}
	void Render();
	SDL_Texture* textr;
	SDL_Rect sr;

};


namespace objf {
	template<class tObj>
	tObj* CreateObj(std::string objName) {
		tObj* obj = new tObj(objName);
		return obj;
	}
	template<class tComp>
	tComp* CreateComp(std::string compName) {
		tComp* cmp = new tComp(compName);
		return cmp;
	}
}