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
#define sum(x) accumulate(x.begin(), x.end(), 0)
#define suml(x) accumulate(x.begin(), x.end(), 0LL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
const int MAXA = 1e7;
vector<int> mind(MAXA+1);
vector<int> primes;


void solve(){
    ll n, k;
    n = 0;
    k = 0;
    cin >> n >> k;
    vector<vl> a(k);
    
    ll temp;
    rep2(n){ 
        cin >> temp;
        a[temp%k].pb(temp);
    }
    ll cost = 0;
    vl side_costs;
    for(int i = 1; i < (k+1)/2; i++){
        
        for (int j = 0; j < min(sz(a[i]), sz(a[k-i])); j++){
            if (a[i][j] == 0 || a[k-i][j] == 0 || i == k-i) continue;
            cost += (a[i][j] + a[k-i][j])/k;
            println("1Packaging " << a[i][j] << " and " << a[k-i][j])
            a[i][j] = 0;
             a[k-i][j] = 0;
        }

    }
    for(int i = 1; i < sz(a[0]); i+=2){ 
        cost += (a[0][i] + a[0][i-1])/2;
        a[0][i] = 0;
        a[0][i-1] = 0;
    }
    if (k%2 == 0){
        for(int i = 1; i < sz(a[k/2]); i+=2){ 
            cost += (a[k/2][i] + a[k/2][i-1])/2;
            a[k/2][i] = 0;
            a[k/2][i-1] = 0;
        }
    }
    int left = 1;
    int right = k-1;
    int j1 = 0;
    int j2 = 0;
    while (left <= right){
        println("LEFT: " << left)
        println("RIGHT: " << right)
        while ((left < k) && (j1 >= sz(a[left])))
        {
            println("L " << left << " k: " << k); left++; right = (k-left); j1 = 0; j2 = 0;
        }
        while ((right < k) && (j2 >= sz(a[right]))){
            println("R " << right << " k: " << k); right++; j2 = 0;
        }
        if (sz(a[right]) == 0 || sz(a[left]) == 0 ) break;  
        println("k " << k << " and right " << right)
        if (right == k) {
            left++;
            right = (k-left);
            continue;
        }
        println("j1: " << j1 << " j2: " << j2);
        cost += (a[left][j1] + a[right][j2])/2;
        a[left][j1] = 0;
        a[right][j2] = 0;
        j1++;
        j2++;
    }
    // unordered_set<ll> skips;
    
 
    // for (int off = 0; off < k; off++){
    //     if (find(skips.begin(), skips.end(), off) != skips.end() || sz(a[off]) == 0 || suml(a[off]) == 0){ skips.insert(off); continue;}

    //     for(int i = k-1; i > 0; i--){
    //         if (off + i < k) continue;
    //         if (find(skips.begin(), skips.end(), i) != skips.end() || sz(a[i]) == 0 || suml(a[i]) == 0){skips.insert(i);  continue;}
    //         for (int j = 0; j < min(sz(a[off]), sz(a[i])); j++){
    //             if (a[i][j] == 0 || a[off][j] == 0  || i == off) continue;
    //             println("2Packaging " << a[i][j] << " and " << a[off][j])
    //             cost += (a[i][j] + a[off][j])/k;
    //             a[i][j] = 0;
    //             a[off][j] = 0;
    //         }

    //     }
    // }
 
    // for (int j = min(sz(a[i]), sz(a[k-i])); j < sz(a[i]); ++ j) side_costs.pb(a[i][j]); 
    // for (int j = min(sz(a[i]), sz(a[k-i])); j < sz(a[k-i]); ++ j) side_costs.pb(a[k-i][j]);
    // if (k %2 == 0){
    //     for (int i = 1; i < sz(a[k/2]); i+=2){
    //         cost += (a[k/2][i-1] + a[k/2][i])/k;
    //     }
    //     if (sz(a[k/2]) % 2 == 1) side_costs.pb(a[k/2][sz(a[k/2])-1]);
    // }

    // for (int i = 1; i < sz(a[0]); i+=2){
    //     cost += (a[0][i-1] + a[0][i])/k;
    // }
    
    // if (sz(a[0]) % 2 == 1) side_costs.pb(a[0][sz(a[0])-1]);
    // sort(side_costs.begin(), side_costs.end(), [&](const ll &a, const ll &b){ return (a%k + b%k)>k; });
    // rep2(sz(side_costs)) print(side_costs[i]);
    // println("");


    // for(int i = 1; i < (sz(side_costs)); i+=2){

    //     cost += (side_costs[i] + side_costs[i-1])/k;
    // }

    cout << cost << endl;
    cout << " --- " << endl;

    
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