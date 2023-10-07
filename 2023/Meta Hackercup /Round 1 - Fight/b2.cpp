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

void solve(){
    int p;
    cin >> p;
    vector<int> factors;

    //  for (int i = (int)sqrt(p); i >= 2; i--){
    //     if (((int)sqrt(p) - i ) * i )
        
    // }

    for (int i = 2; i < (int)sqrt(p)+1; i++){
        while (p%i == 0){
            p /= i;
            factors.pb(i);
        }
    }
    if (p > 1) factors.pb(p); 
    if (accumulate(factors.begin(),factors.end(),0) > 41) {
        cout << -1 << endl;
        return;
    }
    // int j = 1;
    // while (accumulate(factors.begin(),factors.end(),0) <= 41) {
    //     cout << "J IS " << j << endl;
    //     factors.pb(1);
    //     if(factors[j] != 1){
    //         if (factors.size() > 2 && factors[j-1]*factors[j] <= 41){
    //             factors[j-1] = factors[j-1] * factors[j];
    //             for(int i = j; i < factors.size()-1; i++){
    //                 factors[i] = factors[i+1];
    //             }
    
    //             factors[factors.size()-1] = 1;
                
    //         }
    //         else{
    //             j++;
    //         }
                
    //     }
    //     else break;
    // }
    while (accumulate(factors.begin(),factors.end(),0) > 41) factors.pop_back();
    while (accumulate(factors.begin(),factors.end(),0) < 41) factors.pb(1);
    
    if (factors.size() > 100){
        cout << -1 << endl;
        return;
    }
    cout << factors.size() << endl;
    rep2(factors.size()-1) print(factors[i]);
    cout << factors[factors.size()-1] << endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        cout<<"Case #"<<c+1<<": ";
        solve();
    }
}