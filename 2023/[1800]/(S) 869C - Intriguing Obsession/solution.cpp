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
long long fast_pow(long long base, long long exp, long long modulo);
long long choose(vector<long long> &factorial, long long n,long long k,long long m){
    return ((factorial[n] * fast_pow(factorial[k], m-2, m)) % m * fast_pow(factorial[n-k], m-2, m)) % m;
}
long long fast_pow(long long base, long long exp, long long modulo){
    long long res = 1;
    long long cur = base;
    while (exp > 0){
        if (exp % 2 == 1){
            res = (res * cur) % modulo;
        }
        cur = (cur * cur) % modulo;
        exp /= 2;
    }
    return res;
}

void solve(vector<long long> &factorial){
    long long a,b,c;
    long long m = 998244353;
    cin >> a >> b >> c;
    long long bridgesAB = 0;
    long long bridgesBC = 0;
    long long bridgesAC = 0;
     for (long long i = 0; i <= min(a,b); i++){
        bridgesAB = (bridgesAB + (factorial[i] * choose(factorial, a, i, m)) % m * choose(factorial, b, i, m) % m) % m;
     }
    for (long long i = 0; i <= min(b,c); i++){
        bridgesBC = (bridgesBC + (factorial[i] * choose(factorial, b, i, m)) % m * choose(factorial, c, i, m) % m) %m;
    }
    for (long long i = 0; i <= min(a,c); i++){
        bridgesAC = (bridgesAC + (factorial[i] * choose(factorial, a, i, m)) % m * choose(factorial, c, i, m) % m) % m;
    }
    cout << ((bridgesAB%m*bridgesBC%m)%m *bridgesAC%m)%m << endl;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;
    vector<long long> factorial;
    long long n = 1;
    long long m = 998244353;
    factorial.push_back(n);
      for (long long i = 1; i < 15001; i++){
        n = (n * i) % m;
        factorial.push_back(n);
    }
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve(factorial);
    }
}