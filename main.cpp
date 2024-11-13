#include <iostream>

#include "Enemy.h"

#include <memory>

int main() {
	std::unique_ptr<Enemy> enemy;
	enemy = std::make_unique<Enemy>();

	enemy->update();
	enemy->update();
	enemy->update();

	return 0;
}