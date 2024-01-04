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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep2(n) cin >> a[i];
    rep2(n) cin >> b[i];
    if (a[0] != b[0]){
        println("NO");
        return;
    }
    bool inc = 0;
    bool dec = 0;
    rep2(n){
        if (!inc && a[i] < b[i]){
            println("NO");
            return;
        }
        if (!dec && a[i] > b[i]){
            println("NO");
            return;
        }
        if (a[i] == 1) inc = 1;
        if (a[i] == -1) dec = 1;
    }
    println("YES");

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