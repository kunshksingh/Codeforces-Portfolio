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

const int MAXA = 1e6;
vector<int> mind(MAXA+1);
vector<int> primes;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep2(n) cin >> a[i];
    map<int, int> facs;
    int eq = a[0];

    rep2(n){
        int m = mind[a[i]];
        while (a[i] > 1){
            a[i] /= m;
            facs[m] += 1;
            m = mind[a[i]];
        }
        if (a[i] != 1) facs[a[i]] += 1;
    }

    for(auto f: facs){
        if (f.second % n != 0){
            println("NO");
            return;
        }
    }
    println("YES");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
     for (int i = 2; i <= MAXA; ++i) {
        if (mind[i] == 0) {
            primes.emplace_back(i);
            mind[i] = i;
        }
        for (auto &x : primes) {
            if (x > mind[i] || x * i > MAXA) break;
            mind[x * i] = x;
        }
    }
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}
