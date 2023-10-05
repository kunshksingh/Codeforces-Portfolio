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
    int n,m;
    cin >> n >> m;
    string t1;
    string t2;
    cin >> t1;
    cin >> t2;
    bool hasDoubled1 = t1.find("BB") != string::npos || t1.find("RR") != string::npos;
    bool hasDoubled2 = t2.find("BB") != string::npos || t2.find("RR") != string::npos;
    if (!hasDoubled1 && !hasDoubled2){
        println("YES");
        return;
    }
    if (hasDoubled1 && hasDoubled2){
        println("NO");
        return;
    }
    int count = 0;
    for (int i = 1; i < n; i++){
        if (t1[i-1] == t1[i]) count ++;
        if (count >= 2){
            println("NO")
            return;
        }
    }
    count = 0;
    for (int i = 1; i < m; i++){
        if (t2[i-1] == t2[i]) count ++;
        if (count >= 2){
            println("NO")
            return;
        }
    }
    if (t2[m-1] == t1[n-1]){
        println("NO")
        return;
    } 
    println("YES");
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