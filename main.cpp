#include <bits/stdc++.h>
using namespace std;

#include "letterMatrixSource/initializeMatrix.hpp"
#include "letterMatrixSource/encoder.hpp"

// //dbg
// #define DBG_MODE
// long long DBG_COUNT = 0ll;
// void DBG_OUT() { cerr << endl; DBG_COUNT += 1ll; }
// template<typename Front, typename... Back> void DBG_OUT(Front K, Back... T) { cerr << ' ' << K; DBG_OUT(T...); }
// #ifdef DBG_MODE
// template<typename T_Ints> void testList(T_Ints List) { cerr << '#' << DBG_COUNT << " __LIST_ARGS__: ("; DBG_COUNT += 1ll; for (int i = 0; i < List.size(); i++) { cout << List[i] << (i < List.size() - 1 ? ", " : ")\n"); } }
// #define testArgs(...) cerr << '#' << DBG_COUNT << " __VA_ARGS__ (" << #__VA_ARGS__ << "):", DBG_OUT(__VA_ARGS__)
// #else
// template<typename T_Ints> void testList(T_Ints List) { return; }
// #define testArgs(...)
// #endif

template<typename T_Matrix>
void printMatrix(T_Matrix MATRIX) {
    for (int i = 0; i < MATRIX.size(); i++)
        for (int j = 0; j < MATRIX[i].size(); j++)
            cout << MATRIX[i][j] << (j < MATRIX[i].size() - 1 ? ' ' : '\n'); 
}

int main() {
    string input, key;
    cin >> key;

    vector<vector<char>> matrix = initalize_matrix(key);
    cout << encoder(matrix, input);

    printMatrix(matrix);
}