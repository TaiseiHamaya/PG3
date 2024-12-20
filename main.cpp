#include <iostream>
#include <thread>
#include <mutex>

void show() {
	static int  num = 1;
	static std::mutex mutex;
	std::lock_guard lock{ mutex };
	std::cout << "thread " << num << std::endl;
	++num;
 }

int main() {
	std::thread th1{ show };
	std::thread th2{ show };
	std::thread th3{ show };
	if (th1.joinable()) {
		th1.join();
	}
	if (th2.joinable()) {
		th2.join();
	}
	if (th3.joinable()) {
		th3.join();
	}
}