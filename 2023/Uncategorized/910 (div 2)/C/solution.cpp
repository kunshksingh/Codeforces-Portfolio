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
    int n, x;
    cin >> n >> x;
    vi a(n);
    vi b(n);
    rep2(n) cin >> a[i];
    rep2(n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vi c(n);
    int minBeauty = (n);
    int maxBeauty = 0;
    rep2(n){
        if (a[n-(i+1)] > b[i]){ println("1 is true"); maxBeauty++;}
        if (b[n-(i+1)] >= lower_bound(a.begin(), a.end(), b[n-(i+1)]) - a.begin()) {minBeauty = i;}
    }
    println(minBeauty);
    println(maxBeauty);
    if(minBeauty <= x && x <= maxBeauty){
        println("YES");
        for(int j = n-1; j < n-1-x; j--) print(b[j]);
        for(int j = 0; j < x; j ++) print(b[j]);
        println(""); 
    }
    else{
        println("NO");
    }



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