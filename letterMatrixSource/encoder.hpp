vector<char> used;
bool find(vector<char> compair) {
    for (auto i: compair)
        for (auto j: used)
            if (i == j)
                return true;
    return false;
}

string encoder(string input, string key) {
    
    const string alph = "abcdefghijklmnopqrstuvwxyz";
    vector<char> matrix_inital; 

    for (auto i: input)
        matrix_inital.push_back(i);

    for (int i = 0; i < matrix_inital.size();) {
        if (find(matrix_inital)) {
            matrix_inital;
        } else {

            i++;
        }
    }




    vector<vector<char>> matrix(5);
    return input;
}