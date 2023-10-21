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

const int MAX_N = 100000;
int vis[MAX_N];
vector<int> adj[MAX_N];

int dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    int conns = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        conns += dfs(v);
    }
    return conns;
}

void solve(){
    int n;
    cin >> n;
    int val;
    ll conv;
    conv = 0;
    rep2(n){ 
        cin >> val;
        adj[i].pb(val-1);
    }
    vi conns;
    rep2(n){
        conns.pb(dfs(i));
    }
    sort(conns.begin(), conns.end());
    reverse(conns.begin(), conns.end());
    if (conns.size() > 1){
        conns[1] += conns[0];
        rep(1,n){
            conv += pow(conns[i],2);
        }
    }
    else{
        conv += pow(conns[0],2);
    }
    println(conv);
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