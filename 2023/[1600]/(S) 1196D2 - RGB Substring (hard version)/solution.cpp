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

#define rep(a, b) for(int i = a; i < (b); ++i)
#define rep2(b) for(int i = 0; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)

#define println(x) cout << x << endl;
#define print(x) cout << x << " ";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
const int MAXA = 1e7;
vector<int> mind(MAXA+1);
vector<int> primes;

void solve(){
    int n, k;
    cin >> n >> k;
    string q;
    cin >> q;
    int best = 200001;
    vi r(n);
    vi g(n);
    vi b(n);

    rep2(n){
        r[i] = (i % 3 == 0 && q[i] != 'R') + (i % 3 == 1 && q[i] != 'G') + (i % 3 == 2 && q[i] != 'B'); 
        g[i] = (i % 3 == 0 && q[i] != 'G') + (i % 3 == 1 && q[i] != 'B') + (i % 3 == 2 && q[i] != 'R'); 
        b[i] = (i % 3 == 0 && q[i] != 'B') + (i % 3 == 1 && q[i] != 'R') + (i % 3 == 2 && q[i] != 'G'); 
    }

    int currR = 0;
    int currG = 0;
    int currB = 0;

    rep2(k){
        currR += r[i];
        currG += g[i];
        currB += b[i];
    }
    rep(k,n){
        best = min(currR,best);
        best = min(currG,best);
        best = min(currB,best);
        currR += r[i];
        currR -= r[i-k];
        currG += g[i];
        currG -= g[i-k];
        currB += b[i];
        currB -= b[i-k];
    }
    best = min(currR,best);
    best = min(currG,best);
    best = min(currB,best);

    cout << best << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}