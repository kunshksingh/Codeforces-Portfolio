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
    int n;
    cin >> n;
    vector<short> a(n);
    rep2(n) cin >> a[i];
    unordered_set<short> sums;
    unordered_set<short> sums2;
    unordered_set<short> indexes;
    short counter = 0;
    short summation, j;

    rep(2,n){
        summation = a[i-1];
        j = i-2;
        while (j >= 0){
            summation += a[j];
            if (summation > 8000) break;
            sums.insert(summation);
            j--;
        }
        if (sums.find(a[i]) != sums.end()) indexes.insert(i);
    }
    short summation2;
    short counter2 = 0;
    reverse(a.begin(),a.end());
    rep(2,n){
        summation2 = a[i-1];
        j = i-2;
        while (j >= 0){
            summation2 += a[j];
            if (summation2 > 8000) break;
            sums2.insert(summation2);
            j--;
        }
        if (sums2.find(a[i]) != sums2.end()) indexes.insert(n-(i+1));
    }

    cout << sz(indexes) << endl;
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