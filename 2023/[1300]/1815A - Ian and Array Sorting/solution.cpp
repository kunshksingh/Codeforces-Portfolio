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
    int n;
    cin >> n;
    ll val;
    vector<ll> nums;
    nums.pb(-10e17);
    rep(i, 0, n) {
        cin >> val;
        nums.pb(val);
    }
    ll inc;
    rep(i, 1, n+1){
    //         rep(j, 0, n+1){
    //         cout << nums[j] << " ";
    //     }
    //  cout << endl;
        if (n%2 == 1){
            if (i >= 1){
                // cout << "LESS" << endl;
                    inc = (-1* (nums[i-1] - nums[i-2]));
                    nums[i-1] += inc;
                    nums[i] += inc;
            }
        }
        else{
            if((nums[i] < nums[i-1]) && i + 1 < n+1 ){
                    inc = (nums[i-1] - nums[i]);
                    nums[i+1] += inc;
                    nums[i] += inc;
                }

        }
   
    }
    // rep(j, 0, n+1){
    //     cout << nums[j] << " ";
    // }
    // cout << endl;
    
    rep(i, 1, n){
         if (nums[i] > nums[i+1]){

                cout << "NO" << endl;
                return;
            }
    }
    cout << "YES" << endl;
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