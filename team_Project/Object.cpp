#include "Object.h"
void Object::addComponent(Component* cmp) {
	if (m_comps.count(cmp->GetName())) return;
	cmp->setOwner(this);
	m_comps.emplace(cmp->GetName(), cmp);
}