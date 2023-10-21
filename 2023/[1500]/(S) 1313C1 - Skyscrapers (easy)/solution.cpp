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
    vl s(n);
    rep2(n) cin >> s[i];

    vl d_points;
    vector<vl> opts;
    bool brake = false;
    for(int i = 1; i < n-1; i++){

        for (int k = 0; k <= i-1; k++){
            if (s[k] > s[i] && s[i] < s[i+1]) {
                d_points.pb((ll)i);
                break;
            }   
        }
    }
    if (sz(d_points) == 0){
        rep2(n) print(s[i]);
        println("");
        return;
    }
    for (ll p: d_points){
        vl temp = s;
        ll currmin = s[p];
        for (int i = p; i >= 0; i--){
            currmin = min(currmin, s[i]);
            temp[i] = currmin;
        }
        bool relmax = false;
        for (int i = p+1; i < n; i++){
            if (relmax){
                if (temp[i] > temp[i-1]){
                    temp[i] = temp[i-1];
                }
                else{
                    temp[i] = s[i];
                }
            } else {
                if (temp[i] < temp[i-1]){
                    relmax = true;
                    continue;
                }

            }
        }
        opts.pb(temp);
        temp = s;
        currmin = s[p];
        for (int i = p; i < n; i++){
            currmin = min(currmin, s[i]);
            temp[i] = currmin;
        }
        relmax = false;
        for (int i = p-1; i >= 0; i--){
            if (relmax){
                if (temp[i] > temp[i+1]){
                    temp[i] = temp[i+1];
                }
                else{
                    temp[i] = s[i];
                }
            } else {
                if (temp[i] < temp[i+1]){
                    relmax = true;
                    continue;
                }

            }
        }
        opts.pb(temp);
    }
    ll currmax = 0;
    vl maxV(n);
    for (vl v: opts){
        ll summ = accumulate(v.begin(), v.end(), 0LL);
        if (summ > currmax){
            currmax = summ;
            maxV = v;
        }
    }
    


    

    rep2(n) print(maxV[i]);
    println("");
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