#include <iostream>

#include <memory>
#include <list>

class Animal {
public:
	Animal() = default;
	virtual ~Animal() = default;

public:
	virtual void cry() {};
};

class Cat : public Animal {
public:
	void cry() {
		std::cout << "にゃー" << std::endl;
	};
};

class Dog: public Animal {
public:
	void cry() {
		std::cout << "ワン" << std::endl;
	};
};

int main() {
	std::list<std::unique_ptr<Animal>> animals;
	animals.emplace_back(std::make_unique<Cat>());
	animals.emplace_back(std::make_unique<Dog>());

	for (auto& animal : animals) {
		animal->cry();
	}
}
