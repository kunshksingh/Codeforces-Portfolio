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
// const int MAXA = 1e7;
// vector<int> mind(MAXA+1);
// vector<int> primes;


int canfloodFill(vector<string> &grid, int i, int j, int n, int m, set<pii> &visited){
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (find(visited.begin(), visited.end(), make_pair(i,j)) != visited.end()) return 0;
    visited.insert(make_pair(i,j));
    if (grid[i][j] == 'B') return 0;
    if (grid[i][j] == '.') return 1;
    int num = 0;
    num += canfloodFill(grid, i-1, j, n, m,visited);
    num += canfloodFill(grid, i+1, j, n, m,visited);
    num += canfloodFill(grid, i, j-1, n, m,visited);
    num += canfloodFill(grid, i, j+1, n, m,visited);
  
    return num; 
}

int floodFill(vector<string> &grid, int i, int j, int n, int m, set<pii> &visited){
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (find(visited.begin(), visited.end(), make_pair(i,j)) != visited.end()) return 0;
    visited.insert(make_pair(i,j));
    if (grid[i][j] == 'B' || grid[i][j] == '.') return 0;
    int num = 1;
    num += floodFill(grid, i-1, j, n, m,visited);
    num += floodFill(grid, i+1, j, n, m,visited);
    num += floodFill(grid, i, j-1, n, m,visited);
    num += floodFill(grid, i, j+1, n, m,visited);
    
    return num; 
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    string s;
    vector<vi> w_grid;
    rep2(n){
        cin >> s;
        grid[i] = s;
    }
    for(int i = 0; i < n; i++){
        vi t; 
        for (int j = 0; j < m; j++){
            t.pb(0);
        }
        w_grid.pb(t);
    }
    
    //A CPP
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // if (find(whiteV.begin(), whiteV.end(), make_pair(i,j)) != whiteV.end()) continue;
            // print("i: " << i << " " << "j: "<< j);
            bool hasDot = false;
            int adj = 0;
            if (grid[i][j] == 'W'){
                set<pii> visited;
                int num = canfloodFill(grid,i,j,n,m,visited);
                if (num <= 1){w_grid[i][j] = 1;}
                
            }
        }
    }
    //END A CPP
    int num = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // if (find(whiteV.begin(), whiteV.end(), make_pair(i,j)) != whiteV.end()) continue;
            // print("i: " << i << " " << "j: "<< j);
            bool hasDot = falsdfe;
            int adj = 0;
            if (grid[i][j] == '.'){
                
                if ((i+1 < n && w_grid[i+1][j] == 1) || (i-1 >= 0 && w_grid[i-1][j] == 1) || (j+1 < m && w_grid[i][j+1] == 1) || (j-1 >= 0 && w_grid[i][j-1] == 1)){
                    int temp = 0;
                    set<pii> visited;
                    temp += floodFill(grid, i-1, j, n, m,visited);
                    temp += floodFill(grid, i+1, j, n, m,visited);
                    temp += floodFill(grid, i, j-1, n, m,visited);
                    temp += floodFill(grid, i, j+1, n, m,visited);
                    num = max(num,temp);
                    // if (num <= 1){whiteV.clear();return true;}
                }
            }
        }
    }
    println(num);
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
        // if (solve()){
        //      println("YES");
        // }
        // else {
        //     println("NO");
        // }
        solve();
    }
}