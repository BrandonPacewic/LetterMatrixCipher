#include <iostream>
#include <string>
#include <vector>

struct matrix {
	std::vector<std::string> grid;

};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string message, key;
	std::cout << "(Message, Key): ";
	std::cin >> message >> key;

	bool encoding;
	std::cout << "Encoding or Decoding(1, 0): ";
	std::cin >> encoding;
}