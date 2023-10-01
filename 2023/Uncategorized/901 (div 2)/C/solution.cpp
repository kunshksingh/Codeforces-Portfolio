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
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(ll big){
    ll n, m;
    cin >> n >> m;
    if (n % m == 0){
        cout << 0 << endl;
        return;
    }
    if (m % 2 != 0){
        cout << -1 << endl;
        return;
    }
    ll pieces = n%m;
    ll operations = 0;
    ll maxDivs = log2(m);
    
    while (pieces > 0 && maxDivs > 0){
        operations += pieces;
        pieces *= 2;
        if (pieces >= m) pieces = pieces % m;
        maxDivs -= 1;
    }
    if (maxDivs == 0 && pieces > 0){
        cout << -1 << endl;
        return;
    }
    cout<< operations << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    ll t=1;
    cin >> t;
    ll big = pow(2,30);
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve(big);
    }
}