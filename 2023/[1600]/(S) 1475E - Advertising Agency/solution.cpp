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


long long fast_pow(long long base, long long exp, long long modulo);
long long choose(vector<long long> &factorial, long long n, long long k, long long m){
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


void solve(vector<long long> factorial){
    int n, k;
    cin >> n >> k;
    vi nums(n);
    rep2(n) cin >> nums[i];
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int min_element =  nums[k-1];
    int o = count(nums.begin(), nums.end(), min_element);
    k -= find(nums.begin(), nums.end(), min_element)-nums.begin();
    long long m = 1000000007;
    println(choose(factorial,o,k,m));

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    vl factorial;
    long long m = 1000000007;
    int n = 1;
    factorial.push_back(n);
      for (long long i = 1; i < 15001; i++){
        n = (n * i) % m;
        factorial.push_back(n);
    }
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve(factorial);
    }
}