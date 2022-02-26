#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


template<typename A, typename B> std::ostream& operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> std::ostream& operator<<(std::ostream &os, const T_container &v) { os << '{'; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

//dbg
#ifdef DBG_MODE
int64_t DBG_COUNT = 0;
void DBG_OUT() { std::cerr << std::endl; DBG_COUNT++; }
template<typename Front, typename... Back> void DBG_OUT(Front K, Back... T) { std::cerr << ' ' << K; DBG_OUT(T...); }
#define test(...) std::cerr << '#' << DBG_COUNT << " [" << #__VA_ARGS__ << "]:", DBG_OUT(__VA_ARGS__)
#else
#define test(...)
#endif  

template<typename T, const std::size_t Nm>
class uniform_matrix {
private:
    struct _row {
        T* _elements;
        std::size_t _size;

        _row() : 
            _elements{ new T[Nm]}, _size{Nm} { }

        T& operator[](int i) { return _elements[i]; }
        std::size_t size() const { return _size; }
    };  

public:
    uniform_matrix() :_elements{
        new _row[Nm]}, _size{Nm} { }

        _row& operator[](int i) { return _elements[i]; }
        std::size_t size() const { return _size; }

private: 
    _row* _elements;
    std::size_t _size;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uniform_matrix<int, 5> matrix;

    for (int i = 0; i != int(matrix.size()); ++i) {
        for (int j = 0; j != int(matrix.size()); ++j) {
            matrix[i][j] = 5;
        }
    }

    for (int i = 0; i != int(matrix.size()); ++i) {
        for (int j = 0; j != int(matrix.size()); ++j) {
            std::cout << matrix[i][j] << (j >= int(matrix.size()) - 1 ? '\n' : ' ');
        }
    }
}