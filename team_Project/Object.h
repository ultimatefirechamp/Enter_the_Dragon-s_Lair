#pragma once
#include"Game.h"
#include"Components.h"

class Component;
class transform;

class Object
{
public:
	~Object() {
		std::cout << "Object delete\n";
		for (auto iter = m_comps.begin(); iter != m_comps.end(); ++iter) {
			delete(iter->second);
			iter;
		}
		m_comps.clear();
	}

	bool IsOn;

	virtual void Update() = 0;
	virtual void Render() = 0;

	void addComponent(Component* cmp);

	template<class tComp>
	tComp* GetComponent(std::string compName) {
		if (!m_comps.count(compName)) return nullptr;
		return dynamic_cast<tComp*>(m_comps.at(compName));
	}

	std::string GetName() { return m_Name; }
	transform* GetTrans() {
		return trs;
	}

	Object(std::string name) {
		GameManager::getinstance()->objCol.push_back(this);
		IsOn = true;
		m_Name = name;
	}

protected:
	transform* trs;
	std::string m_Name;
	std::map<std::string, Component*> m_comps;
};