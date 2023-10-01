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

void solve(){
    ll n;
    cin >> n;
    vl a(n+1), b(n+1);
    a.pb(0);
    b.pb(0);
    rep(1,n+1) cin >> a[i] >> b[i];
    ll draws = 1;

    rep(1,n+1){
        if (((a[i] == a[i-1])) && ( b[i] == b[i-1])) continue;
    
        draws += max(min(a[i],b[i])-max(a[i-1],b[i-1])+1,0LL);
        
        if (a[i-1] == b[i-1]){
            draws--;
        }
    
    
        // cout << "Draws: " << draws << endl;
        // cout << "Game #" << i << " : " << a[i] << " "<< b[i]<< endl;
    }
    // if (a[n] == b[n] && a[n] != 0) draws++;
    println(draws)

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