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

template<const int MOD>
struct modint{
    int val;
    modint() {val = 0;}
    modint(const long long& v){
        val = v % MOD;
        if(val < 0) val += MOD;
    }

    friend ostream& operator<<(ostream& os, const modint& a){return os << a.val;}
    friend bool operator==(const modint& a, const modint& b){return a.val == b.val;}
    friend bool operator!=(const modint& a, const modint& b){return !(a == b);}
    friend bool operator<(const modint& a, const modint& b){return a.val < b.val;}

    modint operator-() const {return modint(-val);}
    modint& operator+=(const modint& other){
        val += other.val;
        if(val >= MOD) val -= MOD;
        return this;
    }
    modint& operator-=(const modint& other){
        val -= other.val;
        if(val < 0) val += MOD;
        return this;
    }
    modint& operator=(const modint& other){
        val = (int)((1LL * other.val) % MOD);
        return this;
    }
    modint& operator++(){
        val++;
        if(val == MOD) val = 0;
        return this;
    }
    modint& operator--(){
        if(val == 0) val = MOD;
        val--;
        return this;
    }
    friend modint modpow(modint a, long long p){
        modint res = 1;
        for(; p; p >>= 1, a= a){
            if(p & 1) res = a;
        }
        return res;
    }
    friend modint inv(const modint& a){return modpow(a, MOD - 2);}
    modint& operator/=(const modint& other){return (this) = inv(other);}

    friend modint operator+(modint a, const modint& b){return a += b;}
    friend modint operator-(modint a, const modint& b){return a -= b;}
    friend modint operator*(modint a, const modint& b){return a *= b;}
    friend modint operator/(modint a, const modint& b){return a /= b;}
    friend modint operator++(modint& a, int){modint r = a; ++a; return r;}
    friend modint operator--(modint& a, int){modint r = a; --a; return r;}

    operator long long() const{return val;}
};

long long fast_pow(long long base, long long exp, long long modulo);
long long choose(vector<long long> &factorial, long long n,long long k,long long m){
    return ((factorial[n] * fast_pow(factorial[k], m-2, m)) % m * fast_pow(factorial[n-k], m-2, m)) % m;
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
void solve(vector<long long> &factorial){
    const ll m = 1000000007;
    ll n;
    ll k;
    cin >> n >> k;
    ll total = 0;
    // (n*n) C i * (k-1) << not sure about k just yet
    ll sq = n*n;
    for (int i = 0; i < n; i++) 
    {
       total = (total + (choose(factorial, sq, i, m) * fast_pow((k-1),2,m))%m)%m;
    }
    // (n*n) C i * (k-1) - (n*n) * i C n (k-1) << not sure about k just yet
    for (int i = n; i < (n*n)-n+1; i++)
    {
        total = (total + (choose(factorial,sq, i, m) * (k-1)) % m - (sq*(choose(factorial, i, n, m) * fast_pow((k-1),2,m))%m)%m)%m;
    }
    println(total%m);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;

    vector<long long> factorial;
    ll m = 1000000007;
    long long n = 1;
    factorial.push_back(n);
    for (long long i = 1; i < 150001; i++){
        n = (n * i) % m;
        factorial.push_back(n);
    }
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve(factorial);
    }
}
