#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "src/static_mod_type.h"

// Accounting for compile order error
#ifndef _BRANDON_STATIC_MOD_TYPE_C
#include "src/static_mod_type.cc"
#endif

// TODO: Make a matrix class with .h and .cc files
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

void print_matrix(const matrix& grid) {
    for (int row = 0; row < int(grid.size()); ++row) {
    	for (int cell = 0; cell < int(grid[row].size()); ++cell) {
    		std::cout << grid[row][cell] << (
					cell >= int(grid[row].size()) - 1 ? '\n' : ' ');
    	}
    }
}

matrix create_matrix(const std::string& key) {
	const int grid_size = 5;
	const std::string alph = "abcdefghiklmnopqrstuvwxyz";
	std::unordered_set<char> used;
	int row = 0, cell = 0;

	// '\0' is simply a null character, there should be no 
	// null chars left after the matrix is initalized
	matrix grid(grid_size, std::string(grid_size, '\0'));

	auto adjust_row_cell = [](int& cell, int& row) -> void {
		if (!(cell < grid_size)) {
			cell = 0;
			++row;
		}
	};

	for (const char& ch : key) {
		if (used.find(tolower(ch)) != used.end()) { continue; }

		grid[row][cell] = (tolower(ch) == 'j' ? 'i' : tolower(ch));
		used.insert(tolower(ch) == 'j' ? 'i' : tolower(ch));
		adjust_row_cell(++cell, row);
	}

	for (const char& ch : alph) {
		assert(row < grid_size && cell < grid_size);
		if (used.find(ch) != used.end()) { continue; }

		grid[row][cell] = ch;
		adjust_row_cell(++cell, row);
	}

	return grid;
}

const std::unordered_set<char> create_valid_char_set() {
	const std::string valid_chars = "abcdefghijklmnopqrstuvwxyz";
	std::unordered_set<char> set_valid_chars;

	for (const char& ch : valid_chars) {
		set_valid_chars.insert(ch);
	}

	return set_valid_chars;
}

const void assert_valid_chars(const std::unordered_set<char>& valid_chars_set, 
		const std::string& str) {
	for (const char& ch : str) {
		assert(valid_chars_set.count(tolower(ch)));
	}
}

std::string encoder(
		const matrix& grid, const bool& encoding, std::string message) {
	message.erase(std::remove_if(
		message.begin(), message.end(), ::isspace), message.end());

	auto valid_chars_set = create_valid_char_set();
	assert_valid_chars(valid_chars_set, message);

	const int matrix_size = int(grid.size());
	std::unordered_map<char, std::pair<int, int>> map_char_to_cord;

	for (int row = 0; row < matrix_size; ++row) {
		for (int cell = 0; cell < matrix_size; ++cell) {
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
	// to 'x'; defined in README.md. Also at this step every 'j' must 
	// be replaced with in 'i'; defined in README.md
	for (int i = 0; i < int(message.length()); i += 2) {
		if (message[i] == 'j') { message[i] = 'j'; }
		if (message[i+1] == 'j') { message[i+1] = 'j'; }
		if (message[i] == message[i+1]) { message[i+1] = 'x'; }
	}

	std::vector<std::pair<int, int>> message_cords(int(message.length()));

	for (int i = 0; i < int(message.length()); ++i) {
		message_cords[i] = map_char_to_cord[message[i]];
	}

	// ad defines the adjustment needed to find the propper char
	// within the matrix
	const int ad = (encoding ? 1 : -1);
	std::vector<std::pair<int, int>> new_cords;

	// Make new char pairs, static_mod_type is needed for adjustments to assert
	// that the new pair lands on a valid index of the grid this is valid
	// because of the matrix wrap rule defined in README.md The Ceil of the 
	// static mod type is 5 as this will always be the size of the matrix
	for (int i = 0; i < int(message_cords.size()); i += 2) {
		if (message_cords[i].first == message_cords[i+1].first) {
			bp::static_mod_type<int, 5> new_col{message_cords[i].second};
			new_col += ad;
			new_cords.push_back({message_cords[i].first, int(new_col)});

			new_col = message_cords[i+1].second;
			new_col += ad;
			new_cords.push_back({message_cords[i+1].first, int(new_col)});
		}
		else if (message_cords[i].second == message_cords[i+1].second) {
			bp::static_mod_type<int, 5> new_row{message_cords[i].first};
			new_row -= ad;
			new_cords.push_back({int(new_row), message_cords[i].second});

			new_row = message_cords[i+1].first;
			new_row -= ad;
			new_cords.push_back({int(new_row), message_cords[i+1].second});
		}
		else {
			new_cords.push_back({message_cords[i].first, 
				message_cords[i+1].second});
			new_cords.push_back({message_cords[i+1].first,
				message_cords[i].second});
		}
	}

	std::string new_message;

	for (const std::pair<int, int>& cord : new_cords) {
		new_message += grid[cord.first][cord.second];
	}

	return new_message;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string message;
	std::cout << "Message: " << std::flush;
	std::getline(std::cin, message);

	std::string key;
	std::cout << "Key(NO WS): " << std::flush;
	std::cin >> key;
	matrix grid = create_matrix(key);
	print_matrix(grid);

	bool encoding;
	std::cout << "Encoding or Decoding(1, 0): " << std::flush;
	std::cin >> encoding;

	std::string new_message = encoder(grid, encoding, message);
	std::cout << new_message << std::endl;

	return 0;
}