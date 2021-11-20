#include <bits/stdc++.h>
using namespace std;

pair<int, int> find(vector<vector<char>> matrix, char target) {
    pair<int, int> chickenpox;
    for (int i = 0; i < 5; i++)
        for (int k = 0; k < 5; k++) 
            if (matrix[i][k] == target) {
                chickenpox.first = i;
                chickenpox.second = k;
            }

    return chickenpox;
}

vector<char> encoder(vector<vector<char>> matrix, string input, bool encoding = true) {
    vector<pair<int, int>> pairs(input.length() % 2 != 0 ? input.length() + 1 : input.length());

    pair<int, int> X_LOCAL(69, 420);
    for (int i = 0; i < pairs.size(); i++) {
        pairs[i] = find(matrix, i > input.length() - 1 ? 'x' : input[i]);

        if (i + 1 % 2 == 0 && pairs[i] == pairs[i - 1]) {
            X_LOCAL = X_LOCAL.first != 69 ? X_LOCAL : find(matrix, 'x');
            pairs[i] = X_LOCAL;
        }
    }


    vector<char> newPears;
    for (int i = 0; i < pairs.size(); i += 2) 
        if (!(pairs[i].first == pairs[i + 1].first || pairs[i].second == pairs[i + 1].second)) {    
            newPears.push_back(matrix[pairs[i].first][pairs[i + 1].second]);
            newPears.push_back(matrix[pairs[i + 1].first][pairs[i].second]);
        } else 
            if (pairs[i].first == pairs[i + 1].first) {
                int birb = encoding ? pairs[i].second + 1 : pairs[i].second - 1;
                int doger = encoding ? pairs[i + 1].second + 1 : pairs[i + 1].second - 1;
                newPears.push_back(matrix[pairs[i].first][birb > 4 ? 0 : birb < 0 ? 4 : birb]);
                newPears.push_back(matrix[pairs[i + 1].first][doger > 4 ? 0 : doger < 0 ? 4 : doger]);
            } else {
                int tardigrade = encoding ? pairs[i].first + 1 : pairs[i].first - 1;
                int waterbear = encoding ? pairs[i + 1].first + 1 : pairs[i + 1].first - 1;
                newPears.push_back(matrix[tardigrade > 4 ? 0 : tardigrade < 0 ? 4 : tardigrade][pairs[i].second]);
                newPears.push_back(matrix[waterbear > 4 ? 0 : waterbear < 0 ? 4 : waterbear][pairs[i + 1].second]);
            }

    return newPears;
}