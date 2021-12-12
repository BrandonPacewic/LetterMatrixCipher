// #include <bits/stdc++.h>
// using namespace std;

// vector<char> used;
// bool find(char test) {
//     for (auto i : used)
//         if (i == test)
//             return true;
//     return false;
// }

// vector<vector<char>> initalize_matrix(string KEY = "-") {
    
//     const string alph = "abcdefghiklmnopqrstuvwxyz";
//     vector<char> matrix_inital; 

//     if (KEY[0] != '-')
//         for (auto i : KEY) 
//             matrix_inital.push_back((tolower(i) == 'j') ? 'i' : tolower(i));

//     for (int i = 0; i < matrix_inital.size();) 
//         if (find(matrix_inital[i])) {
//             matrix_inital.erase(matrix_inital.begin() + i);
//         } else {
//             used.push_back(tolower(matrix_inital[i]));
//             i++;
//         }
    
//     for (int i = 0; i < 25; i++) 
//         if (!find(alph[i]))
//             matrix_inital.push_back(alph[i]);

//     assert(matrix_inital.size() == 25);

//     vector<vector<char>> matrix(5);
//     int inital_pos = 0;
//     for (int i = 0; i < 5; i++) 
//         for (int j = 0; j < 5; j++) {
//             matrix[i].push_back(matrix_inital[inital_pos]);
//             inital_pos++;
//         }

//     return matrix;
// }

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

        for (auto ch : APLHABET) {
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
    static const std::string APLHABET;
    static const std::unordered_set<char> validChars;

    static std::vector<std::vector<char>> initalize(std::string key = "a") {
        if (key[0] != 'a') {
            assert(assertValidChars(key));
        }

        auto matrix = createMatrix(key);

        return matrix;
    }
};

const std::string matirxInitalizer::APLHABET = "abcdefghiklmnopqrstuvwxyz";
const int matirxInitalizer::MATRIX_SIZE = 5;
const std::unordered_set<char> matirxInitalizer::validChars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };