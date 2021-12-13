#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>

class matirxInitalizer {
private:
    static bool assertValidChars(std::string &key) {
        for (auto &ch : key) {
            ch = tolower(ch);

            if (!validChars.count(ch)) {
                return false;
            }
        }

        return true;
    }

    static std::vector<std::vector<char>> createMatrix(const std::string key) {
        std::unordered_set<char> used;
        std::vector<std::vector<char>> matrix(MATRIX_SIZE, std::vector<char> (MATRIX_SIZE));

        int row = 0, cell = 0;

        for (auto ch : key) {
            if (!used.count(ch)) {
                used.insert(ch);
                matrix[row][cell] = ch == 'j' ? 'i' : ch;
            
                if (cell < MATRIX_SIZE - 1) {
                    cell++;
                } else {
                    cell = 0;
                    row++;
                }
            }
        }

        for (auto ch : ALPHABET) {
            if (!used.count(ch)) {
                used.insert(ch);
                matrix[row][cell] = ch;

                if (cell < MATRIX_SIZE - 1) {
                    cell++;
                } else {
                    cell = 0;
                    row++;
                }
            }
        }

        return matrix;
    }

public:
    static const int MATRIX_SIZE;
    static const std::string ALPHABET;
    static const std::unordered_set<char> validChars;

    static std::vector<std::vector<char>> initalize(std::string key = "a") {
        if (key[0] != 'a' && key.length() != 1) {
            assert(assertValidChars(key));
        }

        auto matrix = createMatrix(key);

        return matrix;
    }
};

const std::string matirxInitalizer::ALPHABET = "abcdefghiklmnopqrstuvwxyz";
const int matirxInitalizer::MATRIX_SIZE = 5;
const std::unordered_set<char> matirxInitalizer::validChars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };