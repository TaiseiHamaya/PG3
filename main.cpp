#include <iostream>
#include <concepts>

// 加算演算子があることを示すconcept
template<typename T>
concept AddOperaotr = requires(const T & v) {
	{ v + v } -> std::same_as<T>;
};

template<AddOperaotr T>
T Min(T&& lhs, T&& rhs) {
	return lhs + rhs;
}

// こんな特殊化しないでconcept(C++20)を使おう
char Min(char&& lhs, char&& rhs) {
	std::cout << "数字以外は代入できません" << std::endl;
	return ' ';
}

int main() {
	int intValue = Min<int>(1, 1);
	float floatValue = Min<float>(1.0f, 1.0f);
	double doubleVaule = Min(1.0, 1.0); // 自動検出
	char charValue = Min(' ', ' ');

	// conceptを使用しているのでCE
	// 今回は特殊化してるためそっちに吸われる
	//int* intPointer{0};
	//auto returnValue = Min<int*>(intPointer, intPointer); 

	std::cout << "Int : " << intValue << std::endl;
	std::cout << "Float : " << floatValue << std::endl;
	std::cout << "Double : " << doubleVaule << std::endl;
	std::cout << "Char : " << charValue << std::endl;
}
