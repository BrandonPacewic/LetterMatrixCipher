#include <bits/stdc++.h>

using namespace std;
#include "encoder.hpp"

//dbg
long long dbg_count = 0ll;
void dbg_out1() { cerr << endl; dbg_count += 1ll; }
template<typename Front, typename... Back> void dbg_out1(Front K, Back... T) { cerr << ' ' << K; dbg_out1(T...); }
#define testArgs(...) cerr << '#' << dbg_count << " __VA_ARGS__ (" << #__VA_ARGS__ << "):", dbg_out1(__VA_ARGS__)

const string data_type[1] = { "St6vectorIiSaIiEE" };
void assertListType() { cerr << '#' << dbg_count << " __LIST_ARGS__: ("; dbg_count += 1ll; }
bool findType(string type) { for (auto i: data_type) { if (i == type) return true; } return false; }
template<typename Arr> void testListInt(Arr List) { assert(findType(typeid(List).name())); assertListType(); for (int i: List) { cout << ' ' << i; } cerr << " )" << endl; }

int main() {
    string input, key;
    cin >> input >> key;

    encoder(input, key);

}