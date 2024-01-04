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
    string p,q;
    cin >> p;
    cin >> q;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int p_sz = sz(p);
    int q_sz = sz(q);
    int cm = p_sz*q_sz;
    for(int k = 0; k < cm; k++){
        i %= p_sz;
        j %= q_sz;
        if (q[j] == 'R' && p[i] == 'S' || q[j] == 'P' && p[i] == 'R' || q[j] == 'S' && p[i] == 'P'){
            x += 1;
        }
        if (p[i] == 'R' && q[j] == 'S' || p[i] == 'P' && q[j] == 'R' || p[i] == 'S' && q[j] == 'P'){
            y += 1;
        }
        i++;
        j++;
    }
    x *= (n/cm);
    y *= (n/cm);
    for(int k = ((int)n/cm)*cm; k < n; k++){
        i %= p_sz;
        j %= q_sz;
        if (q[j] == 'R' && p[i] == 'S' || q[j] == 'P' && p[i] == 'R' || q[j] == 'S' && p[i] == 'P'){
            x += 1;
        }
        if (p[i] == 'R' && q[j] == 'S' || p[i] == 'P' && q[j] == 'R' || p[i] == 'S' && q[j] == 'P'){
            y += 1;
        }
        i++;
        j++;
    }
    print(x);
    println(y);

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