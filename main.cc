#include "letterMatrixSource/initializeMatrix.hpp"
#include "letterMatrixSource/encoder.hpp"
using namespace std;

template<typename T_Matrix>
void printMatrix(const T_Matrix &MATRIX) {
    for (int i = 0; i < MATRIX.size(); i++)
        for (int j = 0; j < MATRIX[i].size(); j++)
            cout << MATRIX[i][j] << (j < MATRIX[i].size() - 1 ? ' ' : '\n'); 
}

int main() {

    freopen("in.txt", "r", stdin);

    string key, input;
    cin >> key >> input;

    auto matrix = matirxInitalizer::initalize(key);

    cout << endl;
    printMatrix(matrix);
    cout << endl;

    cout << encode::generateWord(input, matrix) << endl;
}