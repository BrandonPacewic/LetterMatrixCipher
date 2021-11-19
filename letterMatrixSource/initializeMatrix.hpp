#include <bits/stdc++.h>
using namespace std;

vector<char> used;
bool find(char test) {
    for (auto i: used)
            if (i == test)
                return true;
    return false;
}

string encoder(string input, string key = "-") {
    
    const string alph = "abcdefghiklmnopqrstuvwxyz";
    vector<char> matrix_inital; 

    for (auto i: input) 
        matrix_inital.push_back((tolower(i) == 'j') ? 'i' : tolower(i));

    for (int i = 0; i < matrix_inital.size();) 
        if (find(matrix_inital[i])) {
            matrix_inital.erase(matrix_inital.begin() + i);
        } else {
            used.push_back(tolower(matrix_inital[i]));
            i++;
        }
    
    for (int i = 0; i < 25; i++) 
        if (!find(alph[i]))
            matrix_inital.push_back(alph[i]);

    vector<vector<char>> matrix;
    int inital_pos = 0;
    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) {
            matrix[i].push_back(inital_pos);
            inital_pos++;
        }
    





    return input;
}