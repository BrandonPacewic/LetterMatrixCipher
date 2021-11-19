#include <bits/stdc++.h>
using namespace std;

pair<int, int> find(vector<vector<char>> matrix, char target) {
    pair<int, int> a;
    for (int i = 0; i < 5; i++)
        for (int k = 0; k < 5; k++)
            if (matrix[i][k] == target) {
                a.first = i;
                a.second = k;
            }

    return a;
}


string encoder(vector<vector<char>> matrix, string input) {
        




    return "pass";
}