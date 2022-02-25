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

//dbg
#ifdef DBG_MODE
#include "dbg.h"
#else
#define test(...)
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

	// '\0' is simply a null character, there should be no 
	// null chars left after the matrix is initalized
	matrix grid(grid_size, std::string(grid_size, '\0'));

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
		assert(row < grid_size && cell < grid_size);
		if (used.find(ch) != used.end()) { continue; }

		grid[row][cell] = ch;
		adjust_row_cell();
	}

	return grid;
}


void assert_valid_chars(const std::string &str) {
	const std::string valid_chars = "abcdefghijklmnopqrstuvwxyz";

	for (const char &ch : str) {
		assert(valid_chars.find(tolower(ch)) != std::string::npos);
	}
}

void encoder(const matrix &grid, const bool &encoding, 
		std::string message) {
	const int matrix_size = int(grid.size());
	std::unordered_map<char, std::pair<int, int>> map_char_to_cord;

	// Create map char to cord
	for (int row = 0; row < matrix_size; row++) {
		for (int cell = 0; cell < matrix_size; cell++) {
			map_char_to_cord[grid[row][cell]] = {row, cell};
		}
	}

	// If the message len is not even the letter 'x' is added to make 
	// enough char pairs; defined in README.md
	if (message.length() % 2 != 0) {
		message += 'x';
	}

	assert(message.length() % 2 == 0);

	// If any pair of chars is the same, the second one must be converted
	// to 'x'; defined in README.md
	for (int i = 0; i < int(message.length()); i += 2) {
		if (message[i] == message[i+1]) { message[i+1] = 'x'; }
	}

	// Create message cord pairs
	std::vector<std::pair<int, int>> message_cord_pairs;
	for (const char &ch : message) {
		message_cord_pairs.push_back(map_char_to_cord[ch]);
	}

	// Adjusted modulo, creates a number between 0 and b insted
	// of being between -b and b, this is an oddity found in both C
	// and c++
	// http://www.cplusplus.com/forum/general/19502/
	auto mod = [](int a, int b) -> int {
		a %= b;
		if (a < 0) a += b;
		return a; 
	};

	// ad defines the adjustment needed to find the propper char
	// within the matrix
	const int ad = (encoding ? 1 : -1);
	std::vector<std::pair<int, int>> new_cord_pairs;

	for (int i = 0; i < int(message_cord_pairs.size()); i += 2) {
		if (message_cord_pairs[i].first == message_cord_pairs[i+1].first) {
			new_cord_pairs.push_back({
				// working
			});
		}
	}
}


int main() {
#ifdef DBG_MODE
	freopen("sample_input.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#endif

	std::string message, key;
	std::cout << "(Message, Key): " << std::flush;
	std::cin >> message >> key;

	auto grid = create_matrix(key);
	print_matrix(grid);

	bool encoding;
	std::cout << "Encoding or Decoding(1, 0): " << std::flush;
	std::cin >> encoding;
	test(encoding);

	encoder(grid, encoding, message);

	return 0;
}