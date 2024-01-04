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
// const int MAXA = 1e7;
// vector<int> mind(MAXA+1);
// vector<int> primes;

const ll MAX_N = 3e18 + 7;
map<ll,ll> vis;
map<ll,vector<ll>> adj;
set<ll> globalSet;
vector<ll> globalList;
void dfs(ll u, vl &retList, int n) {
    vis[u] = 1;
    retList.pb(u);
    if (sz(retList) == n) return;
    for (ll v : adj[u]) {
        if (vis[v] || find(globalSet.begin(), globalSet.end(), v) == globalSet.end()) continue;
        dfs(v, retList, n);
        if (sz(retList) == n) return;
        retList.pop_back();
     
    }

}

void solve(){
    int n;
    cin >> n;
    vl a(n);
    rep2(n){
        cin >> a[i];
        adj[a[i]].pb(2*a[i]);
        if (a[i] % 3 == 0) adj[a[i]].pb(a[i]/3);
        globalSet.insert(a[i]);
    }
    
    for (ll i: a){
        
        vl temp;
        dfs(i, temp, n);
        for (ll j: globalSet) vis[j] = 0;

        if (sz(temp) == n){
            rep2(sz(temp)) print(temp[i]);
            println("");
            break;
        }
    }


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