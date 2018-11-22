#include <iostream>
#include <functional>
int f_in(int& counter) {
	std::cout << ++counter << std::endl;
	return counter;
}
	
std::function<int()> f() {
	int counter = 0;
//	return [=] () mutable {std::cout << ++counter << std::endl;return 0;};
	return [=] () mutable {f_in(counter);return 0;};
//	return std::bind(f_in, counter);  // f_in(counter)
}

int main() {
	auto func = f();
	func();
	func();
	func();
}

