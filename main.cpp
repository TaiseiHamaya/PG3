#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <regex>

int main() {
	std::vector<std::string> result;
	std::ifstream file{ "./PG3_2024_03_02.txt" };

	//sstream << file.rdbuf();
	std::string input{ std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>() };

	file.close();

	std::regex regex("(\"([^ \"]*)\")");

	for (std::sregex_iterator it(std::begin(input), std::end(input), regex), end; it != end; ++it) {
		auto&& str = *it;
		result.emplace_back(str[2].str());
	}

	std::sort(result.begin(), result.end());

	for (auto& str : result) {
		std::cout << str << std::endl;
	}

	return 0;
}