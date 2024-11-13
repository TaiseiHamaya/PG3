#pragma once

class Enemy {
public:
	enum class State {
		Approach,
		Shot,
		Leave
	};

public:
	void update();

private:
	void approach();
	void shot();
	void leave();

private:
	State state;

private:
	static inline void (Enemy::* FunctionTable[])() = {
		&Enemy::approach,
		&Enemy::shot,
		&Enemy::leave,
	};
};

