#include <iostream>
#include <random>
#include <thread>

void PrintResult(bool result) {
	auto ynLambda = [&result]()->std::string { return result ? "正解" : "不正解"; };

	std::cout << ynLambda() << std::endl;
}

void CallBack(uint32_t ms, int input, int randomValue) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	int mod2 = randomValue % 2;
	std::cout << (mod2 ? "半" : "丁") << " " << randomValue << std::endl;
	PrintResult(input == mod2);
}

int main() {
	std::random_device device;
	std::mt19937 mt{ device() };
	std::uniform_int_distribution random01{ 1,6 };

	int value = random01(mt);
	int input;

	std::cout << "丁半博打" << std::endl;
	std::cout << "丁 : 0" << std::endl;
	std::cout << "半 : 1" << std::endl;

	std::cin >> input;

	std::cout << "正解は" << std::endl;
	CallBack(3000, input, value);
}