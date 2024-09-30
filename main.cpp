#include <iostream>

const uint32_t Wages(uint32_t hour) {
	if (hour == 1) {
		return 100;
	}
	else {
		return Wages(hour - 1) * 2 - 50;
	}
}

int main() {
	uint32_t hour = 0;
	constexpr uint32_t WagesParHour = 1072;
	uint32_t wagesNormal = 0;
	uint32_t wagesRecursive = 0;
	do {
		++hour;
		wagesNormal = WagesParHour * hour;
		wagesRecursive = Wages(hour);
	} while (wagesNormal > wagesRecursive);
	
	std::cout << "Hour : " << hour << std::endl;
	std::cout << "Normal : " << wagesNormal << std::endl;
	std::cout << "Recursive : " << wagesRecursive << std::endl;
	return 0;
}