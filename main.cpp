#include <iostream>

#include <list>

int main() {
	// list<const char*>とかキモすぎる…
	// あとこの記法許されている理由が静的変数の仕様であることを初めて知った。
	std::list<const char*> yamanoteLine = {
	"Tokyo",
	"Kanda",
	"Akihabara",
	"Okachimachi",
	"Ueno",
	"Uguisudani",
	"Nippori",
	//"Nishi-Nippori",
	"Tabata",
	"Komagome",
	"Sugamo",
	"Otsuka",
	"Ikebukuro",
	"Mejiro",
	"Takadanobaba",
	"Shin-Okubo",
	"Shinjuku",
	"Yoyogi",
	"Harajuku",
	"Shibuya",
	"Ebisu",
	"Meguro",
	"Gotanda",
	"Osaki",
	"Shinagawa",
	//"Takanawa Gateway",
	"Tamachi",
	"Hamamatsucho",
	"Shimbashi",
	"Yurakucho"
	};

	std::cout << "1970" << std::endl;
	for (const auto& station : yamanoteLine) {
		std::cout << station << std::endl;
	}
	std::cout << std::endl;

	// 追加
	yamanoteLine.emplace(std::next(yamanoteLine.begin(), 7), "Nishi-Nippori");

	std::cout << "2019" << std::endl;
	for (const auto& station : yamanoteLine) {
		std::cout << station << std::endl;
	}
	std::cout << std::endl;

	// 追加
	yamanoteLine.emplace(std::next(yamanoteLine.begin(), 25), "Takanawa Gateway");

	std::cout << "2022" << std::endl;
	for (const auto& station : yamanoteLine) {
		std::cout << station << std::endl;
	}
	std::cout << std::endl;
}