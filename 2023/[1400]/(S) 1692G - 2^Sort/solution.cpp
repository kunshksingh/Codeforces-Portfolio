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
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    int n, k;
    cin >> n >> k;
    vi nums(n);
    rep2(n) cin>>nums[i];    
    vector<int> pre(n);
    rep(1,n) pre[i] = 2*nums[i] > nums[i-1];
    pre[0] = 1;
    int counter = 0;
 
    int i = k;
    while(i < n){
        if (pre[i] == 0) {
            i+=k;
            continue;
        }
        bool vool = true;
        int j = i-k+1;
        while(j < i+1){
            
            if (pre[j] == 0){
                 vool = false;
                 i += (j-(i-k+1));
                 break;
            }   
            j++;
        }
        if (vool) {
            counter++;
            i++;
            while(i<n && pre[i] == 1){
                counter++;
                i++;
            }
        }
        else i++;
    }
    println(counter);
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