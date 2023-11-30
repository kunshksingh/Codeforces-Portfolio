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
// vector<int> mind(MAXA+1);
// vector<int> primes;



enum Color { WHITE, GRAY, BLACK };

bool topologicalSortUtil(int v, const vector<vector<bool> > &adj, vector<Color> &color, stack<int> &Stack) {
    // Mark the current node as being processed (GRAY)
    color[v] = GRAY;

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < adj.size(); i++) {
        if (adj[v][i]) {
            if (color[i] == GRAY) {
                // Cycle found
                return true;
            }
            if (color[i] == WHITE && topologicalSortUtil(i, adj, color, Stack)) {
                return true;
            }
        }
    }

    // Mark this node as processed (BLACK)
    color[v] = BLACK;

    // Push current vertex to stack which stores result
    Stack.push(v);
    return false;
}

int topologicalSort(const vector<vector<bool> > &adj) {
    stack<int> Stack;
    int V = adj.size();

    // Initialize color for all vertices
    vector<Color> color(V, WHITE);

    // Call the recursive helper function to store topological sort starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (color[i] == WHITE) {
            if (topologicalSortUtil(i, adj, color, Stack)) {
                // If a cycle is detected, return the current vertex
                return i;
            }
        }
    }

    // If no cycle was found, return -1 or an appropriate value
    return -1;
}

void solve(){
    int n;
    cin >> n;
    map<string, int> str_map;
    vector<string> strs(n);
    vector<vector<bool> > adj_list(n, vector<bool>(n, false));
    rep2(n){cin >> strs[i]; str_map[strs[i]] = i;}
    string s;
    int m;
    rep2(n){
        cin >> s >> m;
        println(m);
        for(int j = 0; j < m; j++){ 
            string temp,t;
            getline(cin, temp);
            stringstream ss(temp);
            println(temp)
            bool isImport = true;
            while(getline(ss, t, ' ')){
                if (isImport){
                    isImport = false;
                    continue;
                }
                if (t.back() == ',') t.pop_back();
                adj_list[str_map[s]][str_map[t]] = 1;
            }
        }
    }
    for (int i = 0; i < sz(adj_list); i++){
        for (int j = 0; j < sz(adj_list[0]); j++){
            print(adj_list[i][j])
        }
        println("")
    }
    int ret = topologicalSort(adj_list);
    if (ret == -1){
        println("SHIP IT");
    }
    else{
        println(strs[ret]);
    }
    
    
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