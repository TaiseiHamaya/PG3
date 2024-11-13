#include "Enemy.h"

#include <iostream>

void Enemy::update() {
	(this->*FunctionTable[static_cast<size_t>(state)])();
}

void Enemy::approach() {
	std::cout << "敵の接近" << std::endl;
	state = State::Shot;
}

void Enemy::shot() {
	std::cout << "敵の射撃" << std::endl;
	state = State::Leave;
}

void Enemy::leave() {
	std::cout << "敵の離脱" << std::endl;
}
