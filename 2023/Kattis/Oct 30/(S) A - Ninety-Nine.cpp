#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;
template <class T> using V = vector<T>;


int main() {
    int n = 0;
    cout << 1 << endl;
    while (n<99) {
        cin >> n;
        if (n % 3 == 0) {
            n += 1;
        }
        else {
            n += (3 - (n%3));
        }
        cout << n << endl;
    }
}
