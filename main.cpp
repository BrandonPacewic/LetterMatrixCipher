// #include <bits/stdc++.h>
// using namespace std;

// #include "letterMatrixSource/initializeMatrix.hpp"
// #include "letterMatrixSource/encoder.hpp"

// template<typename T_Matrix>
// void printMatrix(T_Matrix MATRIX) {
//     for (int i = 0; i < MATRIX.size(); i++)
//         for (int j = 0; j < MATRIX[i].size(); j++)
//             cout << MATRIX[i][j] << (j < MATRIX[i].size() - 1 ? ' ' : '\n'); 
// }

// int main() {
//     string input, key;
//     cin >> key >> input;

//     cerr << endl;
//     vector<vector<char>> matrix = initalize_matrix(key);
//     vector<char> drag = encoder(matrix, input);

//     printMatrix(matrix);
//     cerr << endl;

//     for (int i = 0; i < drag.size(); i++)
//         i < drag.size() - 1 ? cout << drag[i] : cout << drag[i] << '\n';
// }   