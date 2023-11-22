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

bool solve(){
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    if (s1 == s2 || n % 2 == 1) return true;
    if (find(s1.begin(), s1.end(), 'R') == s1.end() && find(s2.begin(), s2.end(), 'R') != s2.end()) return false;
    if (find(s1.begin(), s1.end(), 'B') == s1.end() && find(s2.begin(), s2.end(), 'B') != s2.end()) return false;
    // vi dp(n);
    // for (int i = 1; i < n; i++){
    //     if (s1[i] != s2[i]){
    //         dp[i] = 1;
    //     }
    //     else{
    //         dp[i] = 0;
    //     }
    // }
    // rep2(n-2){
    //     if (dp[i] == dp[i+1] && dp[i+1] == dp[i+2] && dp[i] == 1){
    //         return false;
    //     }
    // }
    for (int i = 1; i < n; i++){
        if (s1[i] == s1[i-1] || s2[i] == s2[i-1] ){
            return true;
        }
    }
    return false;
    
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
        if(solve()){
            println("YES")
        } else{
            println("NO")
        }
    }
}