#include <iostream>
#include <string>
#include <chrono>
#include <format>

int main() {
	std::string copyFrom(100000, 'A');
	std::string copyTo;
	std::string moveFrom(100000, 'A');
	std::string moveTo;

	using timepoint = std::chrono::steady_clock::time_point;
	using duration = std::chrono::steady_clock::duration;

	timepoint startCopy = std::chrono::high_resolution_clock::now();
	copyTo = copyFrom;
	timepoint endCopy = std::chrono::high_resolution_clock::now();

	timepoint startMove = std::chrono::high_resolution_clock::now();
	moveTo = std::move(moveFrom);
	timepoint endMove = std::chrono::high_resolution_clock::now();

	std::cout << std::format("Copy : {}\n", endCopy - startCopy);
	std::cout << std::format("Move : {}\n", endMove - startMove);
}
