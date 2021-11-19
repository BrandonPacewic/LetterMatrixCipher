#include <bits/stdc++.h>
using namespace std;

//dbg
#define DBG_MODE
long long DBG_COUNT = 0ll;
void DBG_OUT() { cerr << endl; DBG_COUNT += 1ll; }
template<typename Front, typename... Back> void DBG_OUT(Front K, Back... T) { cerr << ' ' << K; DBG_OUT(T...); }
#ifdef DBG_MODE
template<typename T_Ints> void testList(T_Ints List) { cerr << '#' << DBG_COUNT << " __LIST_ARGS__: ("; DBG_COUNT += 1ll; for (int i = 0; i < List.size(); i++) { cout << List[i] << (i < List.size() - 1 ? ", " : ")\n"); } }
#define testArgs(...) cerr << '#' << DBG_COUNT << " __VA_ARGS__ (" << #__VA_ARGS__ << "):", DBG_OUT(__VA_ARGS__)
#else
template<typename T_Ints> void testList(T_Ints List) { return; }
#define testArgs(...)
#endif

template<typename T_Pairs>
void printPairs(T_Pairs pairs) {
    for (int i = 0; i < pairs.size(); i++) 
        cout << "pair# " << i << ": " << pairs[i].first << ' ' << pairs[i].second << '\n';  
}   

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

auto encoder(vector<vector<char>> matrix, string input, bool encoding = true) {
    vector<pair<int, int>> pairs(input.length() % 2 != 0 ? input.length() + 1 : input.length());
    
    for (int i = 0; i < pairs.size(); i++) 
        pairs[i] = find(matrix, i > input.length() - 1 ? 'x' : input[i]);
    

    printPairs(pairs);

    vector<char> newPears;
    for (int i = 0; i < pairs.size(); i += 2) {
        if (!(pairs[i].first == pairs[i + 1].first || pairs[i].second == pairs[i + 1].second)) {    
            newPears.push_back(matrix[pairs[i].first][pairs[i + 1].second]);
            newPears.push_back(matrix[pairs[i + 1].first][pairs[i].second]);
        } else {
            if(pairs[i].first == pairs[i + 1].first) {
                newPears.push_back(matrix[pairs[i].first][encoding ? pairs[i].second + 1 : pairs[i].second - 1]);
                newPears.push_back(matrix[pairs[i + 1].first][encoding ? pairs[i].second + 1 : pairs[i].second - 1]);
            } else {

            }
        }
    }

    testList(newPears);    

    return "pass";
}