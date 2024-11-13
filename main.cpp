#include <iostream>

template<typename T, typename U>
class TestTemplate {
public:
	T Min(T t, U u) {
		if (t < u) {
			return t;
		}
		else {
			return static_cast<T>(u);
		}
	}
};

int main() {
	TestTemplate<int, int> intint;
	TestTemplate<int, float> intfloat;
	TestTemplate<int, double> intdouble;
	TestTemplate<float, float> floatfloat;
	TestTemplate<float, double> doublefloat;
	TestTemplate<double, double> doubledouble;

	std::cout << "T = int, U = int : " << intint.Min(1, 2) << std::endl;
	std::cout << "T = int, U = float : " << intfloat.Min(1, 2) << std::endl;
	std::cout << "T = int, U = double : " << intdouble.Min(1, 2) << std::endl;
	std::cout << "T = float, U = float : " << floatfloat.Min(1, 2) << std::endl;
	std::cout << "T = float, U = double : " << doublefloat.Min(1, 2) << std::endl;
	std::cout << "T = double, U = double : " << doubledouble.Min(1, 2) << std::endl;
}
