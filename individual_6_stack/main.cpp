#include <iostream>
#include "Stack.h"
#include "StackList.h"


int main() {
	try {
		StackList<std::string> stak;
		stak.push("Hello world!");
		stak.push("Zdarova mir");
		std::cout << stak.isEmpty() << '\n';
		std::cout << stak.pop() << '\n';
		std::cout << stak.pop() << '\n';
		std::cout << stak.pop() << '\n';
		std::cout << stak.isEmpty() << '\n';
	}
	catch (StackUnderflow error) {
		std::cerr << error.what();
	}
}