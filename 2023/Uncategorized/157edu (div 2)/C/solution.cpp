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
    vector<string> s(n);
    int temp = 0;
    int tickets = 0;
    rep2(n) cin >> s[i];
    rep2(n){
        if (sz(s[i]) == 1) continue;
        set<string> uniqueStrs;
        if (sz(sz[i] >= 2)){
            uniqueStrs.insert((s[i][0]+""+s[i][1]));
        }
        if (sz(sz[i] >= 3)){
            uniqueStrs.insert((s[i][1]+""+s[i][2]));
            uniqueStrs.insert((s[i][0]+""+s[i][2]));
        }
        if (sz(sz[i] >= 4)){
            uniqueStrs.insert((s[i][2]+""+s[i][3]));
            uniqueStrs.insert((s[i][1]+""+s[i][3]));
            uniqueStrs.insert((s[i][0]+""+s[i][3]));
        }
        if (sz(sz[i] == 5)){
            uniqueStrs.insert((s[i][3]+""+s[i][4]));
            uniqueStrs.insert((s[i][2]+""+s[i][4]));
            uniqueStrs.insert((s[i][1]+""+s[i][4]));
            uniqueStrs.insert((s[i][0]+""+s[i][4]));
        }

        if (sz(s[i]) >= 4){
            println("Ticket before at " << i << ": " << tickets);
            for (int j = 0; j <= sz(s)-4; j++){
                if (s[i][j] -'0' + s[i][j+1] -'0'  == s[i][j+2] -'0'+s[i][j+3] -'0'){
                    tickets++;
                }
            }

            
        }
        string prev = "";
        for(string j: uniqueStrs){
            if (prev == ""){
                prev = j;
                continue;
            }
            if (j == prev){
                tickets++;
            }
            prev = j;
        }
        println("Ticket after at " << i << ": " << tickets);
    }    
    cout << tickets << endl;


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