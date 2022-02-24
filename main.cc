#include <iostream>
#include <ostream>
#include <unordered_set>
#include <string>
#include <vector>

#ifndef _BRANDON_MATRIX
#define _BRANDON_MATRIX
typedef std::vector<std::string> matrix;
#endif

matrix create_matrix(const std::string &key) {
	const std::string alph = "abcdefghijklmnopqrstuvwxyz";
	std::unordered_set<char> used;
	int row = 0, cell = 0;
	matrix grid;

	auto adjust_row_cell = [&]() -> void {
		
	};

	for (const char &ch : key) {

	}
}

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