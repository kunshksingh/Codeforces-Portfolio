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
vector<ll> factorial;
long long fast_pow(long long base, long long exp, long long modulo);
long long choose(long long n,long long k,long long m){
    return ((factorial[n] * (fast_pow(factorial[k], m-2, m)) % m) * (fast_pow(factorial[n-k], m-2, m))) % m;
}
long long fast_pow(long long base, long long exp, long long modulo){
    long long res = 1;
    long long cur = base;
    
    while (exp > 0){
        if (exp % 2 == 1){
            res = (res * cur) % modulo;
        }
        cur = (cur * cur) % modulo;
        exp /= 2;
    }
    
    return res;
}

void solve(){
    int n;
    cin >> n;
    vl a(n);
    ll m = 1e9+7;
    rep2(n) cin >> a[i];
    vl cent_pascals(n);

    // if (n%2 == 0){
    rep(0,n){
        cent_pascals[i] = choose(i, i/2, m);
    }
    // }
    // else{
    //      rep(0,n){
    //         cent_pascals[i] = (factorial[(2*(i+1))]*fast_pow(fast_pow(factorial[(i+1)],2,m), m-2,m))/2;
        
    //     }
    // }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll counter = 0;

    rep2(n){
        print(cent_pascals[i]);
        if (i >= ((n+1)/2)) counter = (counter + a[i]*(-cent_pascals[n-(i+1)]))%m;
        else counter = (counter +(a[i]*(cent_pascals[i]))%m)%m;
        if (n%2 == 1 && i == n/2) continue;
    }
    println("");

    cout << counter << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;
    ll n = 1;
    ll m = 10e9+7;
    factorial.pb(n);
      for (long long i = 1; i < 3e6+2; i++){
        n = (n * i) % m;
        factorial.pb(n);
    }
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}