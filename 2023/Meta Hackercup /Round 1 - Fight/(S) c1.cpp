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
    int n, q;
    cin >> n;
    string board;
    cin >> board;
    cin >> q;
    vi brother(q);
    rep2(q) cin >> brother[i];
    // int b_count = count(board.begin(),board.end(),'1');
    // int w_count = count(board.begin(),board.end(),'0');
    vi button_presses(n);
    for (int i:brother){
        button_presses[(i-1)] += 1;
    }

    rep2(n){
        if (button_presses[i] % 2 == 1){
            for (int j = i; j<n; j+=(i+1)) {
                if (board[j] == '1') board[j] ='0';
                else board[j] = '1';
            }
        }
    }
    int n_black = count(board.begin(),board.end(),'1');
    int n_white = count(board.begin(),board.end(),'0');

    int moves = 0;
    rep2(n){
        if (board[i] == '1') {
            moves++;
            for (int j = i; j<n; j+=(i+1)) {
                if (board[j] == '1') board[j] ='0';
                else board[j] = '1';
            }
        }
    }
    println(moves);
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