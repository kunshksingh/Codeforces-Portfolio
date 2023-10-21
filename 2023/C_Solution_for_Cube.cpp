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
    vi cube(24);
    rep2(24) cin >> cube[i];
    int val1 = 0;
    int val2 = 0;
    int prev_val1 = 0;
    int prev_val2 = 0;

    vi curr = {0,0,0,0};
    vi pattern = {0,0,0,0};

    for(int i = 0; i < 24; i+=4){
        if (cube[i] == cube[i+1] && cube[i+1] == cube[i+2] && cube[i+2] == cube[i+3]) continue;
        val1 = cube[i];
        curr[0] = 1;
        if (cube[i+1] != val1){ 
            val2 = cube[i+1];
            curr[1] = 2;
        } else curr[1] = 1;
        if (cube[i+2] != val1){
            if (val2 != 0 && cube[i+2] != val2) return false;
            else{ val2 = cube[i+3]; curr[2] = 2;}
        }
        else curr[2] = 1;
        if (cube[i+3] != val1){ 
            if (val2 != 0 && cube[i+3] != val2) return false;
            else {val2 = cube[i+3]; curr[3] = 2;}
        }
        else curr[3] = 1;
        if (pattern[0] == 0){
            pattern = curr;
            break;
        }
    }
    if (pattern[0] == 1 && pattern[1] == 1 && pattern[2] == 2 && pattern[2] == 2){

    }
    
    return true;
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
        
        if (solve()) {println("YES");}
        else{ println("NO");}
    }
}