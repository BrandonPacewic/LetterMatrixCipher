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

template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> std::ostream& operator<<(std::ostream &os, const T_container &v) { os << '{'; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }


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
		adjust_row_cell();
	}

	for (const char &ch : alph) {
		if (used.find(ch) != used.end()) { continue; }

		grid[row][cell] = ch;
	}

	return grid;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string message, key;
	std::cout << "(Message, Key): " << std::flush;
	std::cin >> message >> key;

	matrix grid = create_matrix(key);
	std::cout << grid;

	// bool encoding;
	// std::cout << "Encoding or Decoding(1, 0): " << std::flush;
	// std::cin >> encoding;
}