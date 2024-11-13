#include <iostream>

#include <numbers>

class IShape {
public:
	IShape() = default;
	virtual ~IShape() = default;

public:
	virtual float size() = 0;
	virtual void draw() = 0;
};

class Circle : public IShape {
public:
	Circle(float radius_) : radius(radius_) {};

public:
	float size() override {
		return static_cast<float>(std::numbers::pi) * radius * radius;
	};
	void draw() override {
		std::cout << "Circle size(radius : " << radius << ") = " << size() << std::endl;
	};

private:
	float radius;
};

class Rectangle : public IShape {
public:
	Rectangle(float height_, float width_) : height(height_) , width(width_) {};

public:
	float size() override {
		return height * width;
	};
	void draw() override {
		std::cout << "Rectangle size(height : " << height << ", width : " << width << ") = " << size() << std::endl;
	};

private:
	float height;
	float width;
};

int main() {
	Circle circle{ 2 };
	circle.draw();
	Rectangle rect{ 4,4 };
	rect.draw();
}