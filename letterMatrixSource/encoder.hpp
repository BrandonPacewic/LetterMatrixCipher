// #include <bits/stdc++.h>
// using namespace std;

// pair<int, int> find(vector<vector<char>> matrix, char target) {
//     pair<int, int> chickenpox;
//     for (int i = 0; i < 5; i++)
//         for (int k = 0; k < 5; k++) 
//             if (matrix[i][k] == target) {
//                 chickenpox.first = i;
//                 chickenpox.second = k;
//             }

//     return chickenpox;
// }

// vector<char> encoder(vector<vector<char>> matrix, string input, bool encoding = true) {
//     vector<pair<int, int>> pairs(input.length() % 2 != 0 ? input.length() + 1 : input.length());

//     pair<int, int> X_LOCAL(69, 420);
//     for (int i = 0; i < pairs.size(); i++) {
//         pairs[i] = find(matrix, i > input.length() - 1 ? 'x' : input[i]);

//         if (i + 1 % 2 == 0 && pairs[i] == pairs[i - 1]) {
//             X_LOCAL = X_LOCAL.first != 69 ? X_LOCAL : find(matrix, 'x');
//             pairs[i] = X_LOCAL;
//         }
//     }


//     vector<char> newPears;
//     for (int i = 0; i < pairs.size(); i += 2) 
//         if (!(pairs[i].first == pairs[i + 1].first || pairs[i].second == pairs[i + 1].second)) {    
//             newPears.push_back(matrix[pairs[i].first][pairs[i + 1].second]);
//             newPears.push_back(matrix[pairs[i + 1].first][pairs[i].second]);
//         } else 
//             if (pairs[i].first == pairs[i + 1].first) {
//                 int birb = encoding ? pairs[i].second + 1 : pairs[i].second - 1;
//                 int doger = encoding ? pairs[i + 1].second + 1 : pairs[i + 1].second - 1;
//                 newPears.push_back(matrix[pairs[i].first][birb > 4 ? 0 : birb < 0 ? 4 : birb]);
//                 newPears.push_back(matrix[pairs[i + 1].first][doger > 4 ? 0 : doger < 0 ? 4 : doger]);
//             } else {
//                 int tardigrade = encoding ? pairs[i].first + 1 : pairs[i].first - 1;
//                 int waterbear = encoding ? pairs[i + 1].first + 1 : pairs[i + 1].first - 1;
//                 newPears.push_back(matrix[tardigrade > 4 ? 0 : tardigrade < 0 ? 4 : tardigrade][pairs[i].second]);
//                 newPears.push_back(matrix[waterbear > 4 ? 0 : waterbear < 0 ? 4 : waterbear][pairs[i + 1].second]);
//             }

//     return newPears;
// }


#include <string>
#include <vector>

//modulo http://www.cplusplus.com/forum/general/19502/
template<typename T, typename OP> struct modulo { T bace; }; enum { mod };
template<typename T> modulo<T, decltype(mod)> operator<(const T& front, decltype(mod)) { return  { front }; }
int operator>(modulo<int, decltype(mod)> tail, int exponent) { int& bace = tail.bace; return bace % exponent < 0 ? (bace % exponent) + exponent : bace % exponent; }


class encode {
private:
    static const std::pair<int, int> findCharInMatrix(std::vector<std::vector<char>> MATRIX, char target) {
        for (int i = 0; i < MATRIX.size(); i++) {
            for (int k = 0; k < MATRIX[i].size(); k++) {
                if (MATRIX[i][k] == target) {
                    return {i, k};
                }
            }
        }

        return {-1, -1};
    }

    static std::vector<std::pair<int, int>> createInitalRowColPairs(const std::vector<std::vector<char>> MATRIX, const std::string input) {
        std::vector<std::pair<int, int>> initalPairs(input.length() % 2 != 0 ? input.length() + 1 : input.length());

        for (int i = 0; i < initalPairs.size(); i++) {
            initalPairs[i] = findCharInMatrix(MATRIX, i > input.length() - 1 ? 'x' : tolower(input[i]) == 'j' ? 'i' : tolower(input[i]));

            if (i + 1 % 2 == 0 && initalPairs[i] == initalPairs[i - 1]) {
                initalPairs[i] = findCharInMatrix(MATRIX, 'x');
            }
        }

        return initalPairs;
    }

    static std::string createNewString(const std::vector<std::vector<char>> MATRIX, const std::vector<std::pair<int, int>> initalPairs, const bool encoding = true) {
        const int matrixRows = MATRIX.size();
        const int matrixCols = MATRIX[0].size();

        std::string newMessage = "";

        for (int i = 0; i < initalPairs.size(); i += 2) {
            if ((initalPairs[i].first != initalPairs[i - 1].first) && (initalPairs[i].second != initalPairs[i - 1].second)) {
                newMessage += MATRIX[initalPairs[i].first][initalPairs[i + 1].second];
                newMessage += MATRIX[initalPairs[i + 1].first][initalPairs[i].second];

            } else if (initalPairs[i].first == initalPairs[i + 1].first) {
                newMessage += encoding ? (initalPairs[i].second + 1) <mod> matrixCols : (initalPairs[i].second - 1) <mod> matrixCols;
                newMessage += encoding ? (initalPairs[i + 1].second + 1) <mod> matrixCols : (initalPairs[i + 1].second - 1) <mod> matrixCols;

            } else if (initalPairs[i].second == initalPairs[i + 1].second) {
                newMessage += encoding ? (initalPairs[i].first + 1) <mod> matrixRows : (initalPairs[i].first - 1) <mod> matrixRows;
                newMessage += encoding ? (initalPairs[i + 1].first + 1) <mod> matrixRows : (initalPairs[i + 1].first - 1) <mod> matrixRows;
            }
        }

        return newMessage;
    }

public:
    static std::string generateWord(std::string key, const std::vector<std::vector<char>> MATRIX) {

    }


};