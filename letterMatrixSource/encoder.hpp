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

vector<char> encoder(vector<vector<char>> matrix, string input, bool encoding = true) {
    vector<pair<int, int>> pairs(input.length() % 2 != 0 ? input.length() + 1 : input.length());
    
    for (int i = 0; i < pairs.size(); i++) 
        pairs[i] = find(matrix, i > input.length() - 1 ? 'x' : input[i]);

    vector<char> newPears;
    for (int i = 0; i < pairs.size(); i += 2) 
        if (!(pairs[i].first == pairs[i + 1].first || pairs[i].second == pairs[i + 1].second)) {    
            newPears.push_back(matrix[pairs[i].first][pairs[i + 1].second]);
            newPears.push_back(matrix[pairs[i + 1].first][pairs[i].second]);
        } else 
            if(pairs[i].first == pairs[i + 1].first) {
                newPears.push_back(matrix[pairs[i].first][encoding ? pairs[i].second + 1 : pairs[i].second - 1]);
                newPears.push_back(matrix[pairs[i + 1].first][encoding ? pairs[i + 1].second + 1 : pairs[i].second - 1]);
            } else {
                newPears.push_back(matrix[encoding ? pairs[i].first + 1 : pairs[i].first - 1][pairs[i].second]);
                newPears.push_back(matrix[encoding ? pairs[i + 1].first + 1 : pairs[i + 1].first - 1][pairs[i + 1].second]);
            }
        
    return newPears;
}