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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;



void solve(vector<long long> &factorial){
    long long counter = 0;
    
    string bitstring;
    cin >> bitstring;
    int n = bitstring.length();
    long long M = 998244353;
    
 
 
    // bitmask = "10"*(len(bitstring)//2) + "1" * int(len(bitstring) % 2 == 1)
    // bitmask2 = "01"*(len(bitstring)//2) + "0" * int(len(bitstring) % 2 == 1)
    // bitset<20000> bitmask = 0b1010101010;
    // bitset<20000> bitmask = 0b0101010101;
    bool vool = false;
    long long countiguosity = 1;
    long long goat = 1;
    for (int i = 1; i < n; i++){
        if (bitstring[i] == bitstring[i-1]){
            counter += 1;
            bitstring[i] = bitstring[i-1];
            goat += 1;
        }else{
            countiguosity = (countiguosity * goat) % M;
            goat = 1;
        }
    }

    countiguosity = (countiguosity * goat) % M;
    cout <<  counter % M << " " << (factorial[counter]*countiguosity) % M << endl;
}

int main(){
    long long num = 1;
    vector<long long> factorial;
    factorial.push_back(1) ;
    long long M = 998244353;
    for (int i = 1; i < 200001; i++){
        num = (num * i) % M;
        factorial.push_back(num);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        solve(factorial);
    }
}