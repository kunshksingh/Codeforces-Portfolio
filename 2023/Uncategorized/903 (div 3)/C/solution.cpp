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
    int n;
    cin >> n;
    vector<vector<char>> grid;
    vector<char> temp(n);
    rep2(n){
        for (int j = 0; j < n; j++) cin >> temp[j];
        grid.pb(temp);
    }

    int moves = 0;
    // int val1;//,val2,val3,val4;
    int maximum;
    vector<vector<char>> grid_rotate;

    // rep2(n){
    //     for(int j = 0; j < n; j++){
    //         temp[n-j-1] = grid[j][i];
    //     }
    //     grid_rotate.pb(temp);
    // }
    // rep2(n){
    //     for(int j = 0; j < n; j++){
    //         if ((grid[i][j]-'a') < (grid_rotate[i][j]-'a'))
    //             moves += (grid_rotate[i][j]-'a') - (grid[i][j]-'a');
                
    //     }
    // }
    int val1, val2, val3, val4;
      rep2(n/2){ // Mini-square
        for(int j = 0; j < n/2; j++){
            val1 = grid[i][j]-'a';
            val2 = grid[j][n-1-i]-'a';
            val3 = grid[n-j-1][i]-'a';
            val4 = grid[n-1-i][n-1-j]-'a';
            maximum = max(val1,max(val2,max(val3,val4)));
            moves += maximum - val1;
            moves += maximum - val2;
            moves += maximum - val3;
            moves += maximum - val4;
        }
    }

    println(moves)
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
  // rep2(n/2){ // Mini-square
    //     for(int j = 0; j < n/2; j++){
    //         val1 = grid[i][j]-'a';
    //         val2 = grid[i][n-1-j]-'a';
    //         val3 = grid[n-1-i][j]-'a';
    //         val4 = grid[n-1-i][n-1-j]-'a';
    //         maximum = max(val1,max(val2,max(val3,val4)));
    //         moves += maximum - val1;
    //         moves += maximum - val2;
    //         moves += maximum - val3;
    //         moves += maximum - val4;
    //     }
    //     println("Moves after row 1: " << moves)
    // }
    // if (n % 2 == 1){
    //     rep2(n/2){ // Line
    //         val1 = grid[i][n/2]-'a';
    //         val2 = grid[n/2][i]-'a';
    //         val3 = grid[n/2][n-1-i]-'a';
    //         val4 = grid[n-1-i][n/2]-'a';
    //         maximum = max(val1,max(val2,max(val3,val4)));
    //         moves += maximum - val1;
    //         moves += maximum - val2;
    //         moves += maximum - val3;
    //         moves += maximum - val4;
    //     }
    // }