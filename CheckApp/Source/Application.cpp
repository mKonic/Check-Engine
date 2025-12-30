#include <iostream>
#include "Core.h"

__declspec(dllimport) void print();


int main() {
	print();
	std::cin.get();
}
