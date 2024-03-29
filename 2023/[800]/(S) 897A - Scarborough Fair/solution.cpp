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

struct dsu{
    int N;
    vector<int> p, s;
    dsu(int _n){
        N = _n + 5;
        p.resize(N); s.resize(N);
        iota(p.begin(), p.end(), 0);
        fill(s.begin(), s.end(), 1);
    }
    int size(int a){
        return s[find(a)];
    }
    int find(int a){
        if(p[a] == a) return a;
        p[a] = find(p[a]);
        return p[a];
    }
    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(s[a] > s[b]) swap(a, b);
        s[b] += s[a];
        p[a] = b;
        return true;
    }
    bool same(int a, int b){
        return find(a) == find(b);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l, r;
    char c1, c2;
    // dsu arr(26);
    rep2(m){
        cin >> l >> r >> c1 >> c2;
        l--;
        while (l < r){
            if (s[l] == c1){
                s = s.substr(0, l) + c2 + s.substr(l+1);
            }
            l++;
        }
        // arr.unite(c1-'a', c2-'a');
    }
    println(s);
    // char temp;
    // rep2(n){
    //     temp = 'a'+arr.find(s[i]-'a');
    //     cout << temp;
    // }
    // cout << endl;
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