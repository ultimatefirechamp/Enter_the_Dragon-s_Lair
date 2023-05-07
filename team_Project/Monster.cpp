#include "Monster.h"
void Monster::Render() {
	sprite_->Render();
}
void Monster::GetDamaged(int damage) {
	hp -= damage;
	if (hp <= 0) {
		IsAlive = false;
		hp = 0;
	}
}

void Monster::move() {

}