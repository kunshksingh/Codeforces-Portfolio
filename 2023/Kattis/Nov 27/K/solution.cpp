#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>
#include <climits>

using namespace std;
using ll = long long;
using ld = long double;
template <class T> using V = vector<T>;



int main() {
    int x; cin >> x;
    while(x--){
        int n; cin >> n;
        int m = n;
        V<int> digits;
        while(m > 0){
            digits.push_back(m % 10);
            m /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        int out = 0;
        int max_digits = floor(log10(n)) + 1;
        if(max_digits == 1){
            out = n - 1;
            cout << out << endl;
            continue;
        }
        //sum to get the number of digits
        out += 9 * (max_digits - 1);
        out += 10 * (max_digits - 1) * (max_digits - 2) / 2;
        int temp = 0;
        for(int i : digits){
            temp += i;
        }

        //if its some number and only 0's
        if(temp == digits[0]){
            if(digits[0] == 1){
                cout << out << endl;
                continue;
            }
            else if(digits[0] == 2){
                out += (max_digits - 1) * 10;
            }
            else{
                out += (max_digits - 1) * 10 + digits[0] - 1;
            }
            cout << out << endl;
            continue;
        }
        if(digits[0] == 1){
            for(int i = 1; i < digits.size(); i++){
                if(digits[i] != 0){
                    out += digits[i] + 1;
                }
            }
            if(digits[digits.size() - 1] != 0) {
                out--;
            }
        }
        else{
            for(int digit : digits){
                out += digit + 1;
            }
            out -= 2;
        }
        cout << out << endl;
    }
}