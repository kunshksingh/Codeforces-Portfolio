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
vector<int> tape(200);
vi tuplet(5);
bool bfs_tm(vector<vector<pair<vector<int>,int>>> &s, int curr, int L){ 
    if (curr <= -1) return true;
    if (L < 0) return false;
    bool ans = true;
    if(s[curr].size() == 0) return false; 
    rep2(s[curr].size()){
        if (s[curr][i].second == 1) return false;
        if (s[curr][i].first[])
            ans &= bfs_tm(s, s[curr][i].first, L-1);
        
    }
    return ans;
}
void solve(){
    int L, S;
    cin >> L;
    cin >> S;
    vector<pair<vector<int>,int>> states(100);
    for (int i = 0; i < 2*S*6+1; i++){
        if (i%6 != 5) cin >> tuplet[i%6];
        if (i%6 == 5){
            // if (tuplet[4] == 0){ 
            //     if (tuplet[2] == -1)states[tuplet[0]].pb(make_pair(-1,0));
            //     else if(tuplet[2]-1 < 0) states[tuplet[0]].pb(make_pair(0,0));
            //     else states[tuplet[0]].pb(make_pair(tuplet[2],0));
            // }
            // else{
                
            // } 
            states[(int)i/6] = make_pair(tuplet,0);
        } 
    }

    // rep2(states.size()){
    //     for (int j = 0; j < states[i].size(); j++)
    //         println("State "<< i<< " goes to state " << states[i][j].first)
    // }   

    cout << (int)bfs(states, 0, L);
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