#include <cassert>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <string>
#include <vector>

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