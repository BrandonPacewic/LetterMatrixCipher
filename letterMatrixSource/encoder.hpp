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
    vector<pair<char, char>> pairs(input.length() % 2 != 0 ? input.length() / 2 + 1 : input.length() / 2);

    testArgs(pairs.size());


    return "pass";
}