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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define rep(a, b) for(int i = a; i < (b); ++i)
#define rrep(a, b) for(int i = a; i > (b); --i)
#define rep2(b) for(int i = 0; i < (b); ++i)
#define rrep2(a) for(int i = a; i >= 0; --i)
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

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };


void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep2(n) cin >> a[i];
    vector<bool> stack(1e6+1);
    set<int> used;
    int day = 0;
    vi parts;
    parts.pb(0);
    rep2(n){
        if (a[i] < 0){
            if (stack[abs(a[i])] != 1){
                println(-1);
                return;
            }
            stack[abs(a[i])] = 0;
            used.insert(abs(a[i]));
            day--;
        }
        else{
            if (stack[a[i]] == 1 || find(used.begin(), used.end(), a[i]) != used.end()){
                println(-1);
                return;
            }
            stack[a[i]] = 1;
            day++;
        }
        if (day == 0){
            parts.pb((i+1));
            used.clear();

        }
    }
    if (day != 0) {
        println(-1);
        return;
    }
    println(sz(parts)-1);
    rep(1,sz(parts)) print(parts[i]-parts[i-1]);
    println("");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}