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

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; 
    cin >> n;
    string init;
    cin >> init;
    int maxlights = 0;
    vector<int> light_status;
    rep(i, 0, n) light_status.push_back((int) (init[i] - '0'));
    

    vector<pii> lights;
    for (int i = 0; i < n; i++){
        int ai, bi;
        cin >> bi >> ai;
        lights.push_back(make_pair(ai,bi));
    }
    for (int i = 0; i < 2521; i++){ // 2520 is the lcm of 1-10
        int mycount = count(light_status.begin(), light_status.end(),1);
        maxlights = max(maxlights, mycount);
        for (int j = 0; j < n; j++){    
            if (i >= lights[j].first && (i- lights[j].first) % lights[j].second == 0){
                if (light_status[j] == 0){
                    light_status[j] = 1;
                }
                else{
                    light_status[j] = 0;
                }
            }
        }
    }
    cout << maxlights << endl;
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