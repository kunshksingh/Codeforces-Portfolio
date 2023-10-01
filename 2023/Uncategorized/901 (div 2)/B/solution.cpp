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

void solve(){
    ll n,m,k;
    vector<ll> jellyApples;
    vector<ll> gellyApples;
 
    ll val;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++ ){
        cin >> val;
        jellyApples.pb(val);
    }
    for (ll i = 0; i < m; i++ ){
        cin >> val;
        gellyApples.pb(val);
    }
    sort(gellyApples.begin(), gellyApples.end());
    sort(jellyApples.begin(), jellyApples.end());
    int start = 1;
    if (k % 2 == 0 && k > 500){
        start = k-201;
    } else if (k > 500){
        start = k-202;
    }
    for (ll i = start; i < k+1; i ++){
        if (i % 2 == 0) {
            if (jellyApples[n-1] > gellyApples[0]){
                swap(jellyApples[n-1],gellyApples[0]);
            }
            sort(gellyApples.begin(), gellyApples.end());
            sort(jellyApples.begin(), jellyApples.end());
        }
        else{
            if (jellyApples[0] < gellyApples[m-1]){
                swap(jellyApples[0],gellyApples[m-1]);
            }
            sort(gellyApples.begin(), gellyApples.end());
            sort(jellyApples.begin(), jellyApples.end());
        }
    }
    ll summation = 0;
    for (ll i = 0; i < n; i++) summation += jellyApples[i];
    cout << summation << endl;
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