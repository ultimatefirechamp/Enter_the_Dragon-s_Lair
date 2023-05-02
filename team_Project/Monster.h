#pragma once
#include"Object.h"
class Monster:public Object
{
public:
	Monster(std::string name) : Object(name) {
		trs = objf::CreateComp<transform>("transform");
		addComponent(trs);
	}

	void Update() {}
	void Render() {}
private:

};

