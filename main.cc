#include <cassert>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifndef _BRANDON_MATRIX
#define _BRANDON_MATRIX
typedef std::vector<std::string> matrix;
#endif


void print_matrix(const matrix &grid) {
    for (int row = 0; row < int(grid.size()); row++) {
    	for (int cell = 0; cell < int(grid[row].size()); cell++) {
    		std::cout << grid[row][cell] << (
					cell >= int(grid[row].size()) - 1 ? '\n' : ' ');
    	}
    }
}


matrix create_matrix(const std::string &key) {
	const int grid_size = 5;
	const std::string alph = "abcdefghiklmnopqrstuvwxyz";
	std::unordered_set<char> used;
	int row = 0, cell = 0;

	// % is used as a null character, there should be no 
	// %s' left after the matrix is initalized
	matrix grid(grid_size, std::string(grid_size, '%'));

	auto adjust_row_cell = [&]() -> void {
		cell++;

		if (!(cell < grid_size)) {
			cell = 0;
			row++;
		}
	};

	for (const char ch : key) {
		if (used.find(tolower(ch)) != used.end()) { continue; }

		grid[row][cell] = (tolower(ch) == 'j' ? 'i' : tolower(ch));
		used.insert(tolower(ch) == 'j' ? 'i' : tolower(ch));
		adjust_row_cell();
	}

	for (const char &ch : alph) {
		if (used.find(ch) != used.end()) { continue; }

		grid[row][cell] = ch;
		adjust_row_cell();
	}

	return grid;
}


std::string encoder(const matrix &grid, std::string message, 
												const bool &encoding) {
	const int matrix_size = int(grid.size());
	std::unordered_map<char, std::pair<int, int>> map_char_to_cord;

	// Create map char to cord
	for (int row = 0; row < matrix_size; row++) {
		for (int cell = 0; cell < matrix_size; cell++) {
			map_char_to_cord[grid[row][cell]] = {row, cell};
		}
	}

	// If the message len is not even the letter 'x' is added to make 
	// enough char pairs $defined in README.md
	if (message.length() % 2 != 0) {
		message += 'x';
	}

	assert(message.length() % 2 == 0);

	// Create message pairs
	std::vector<std::pair<char, char>> message_pairs;
	for (int i = 0; i < message.length(); i += 2) {
		message_pairs.push_back({message[i], message[i + 1]});
	}

	// ad defines the adjustment needed to find the propper char
	// within the matrix
	const int ad = (encoding ? 1 : -1);
	std::string new_message;

	auto modulo = [](int a, int b) -> int {
		a %= b;
		if (a < 0) a += b;
		return a; 
	};


}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string message, key;
	std::cout << "(Message, Key): " << std::flush;
	std::cin >> message >> key;

	auto grid = create_matrix(key);
	print_matrix(grid);

	bool encoding;
	std::cout << "Encoding or Decoding(1, 0): " << std::flush;
	std::cin >> encoding;


}