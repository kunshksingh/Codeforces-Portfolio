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
#define print(x) cout << x << 
;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    string a, b;
    cin >> a;
    cin >> b;
    map<char, int> counter;
    rep(0, b.length()) counter[b[i]] += 1;
    vector<int> l(a.length());
    string longest = "";
    string temp;
    int i = 0;
    int j = 1;
    while(j < a.length()){
        if (counter[a[j]] == 0){
            
            if (longest.length() < temp.length()){
                longest = temp;
                temp = "";
            }
            while (a[i] != a[j]){
                counter[a[i]]++;
                i++;
            } 
            j = i+1;
            temp = a.substr(i,j)
        }
        else{
            counter[a[j]]--;
            j++;
            temp += a[j];
        }
    }
    if (temp.length() > longest.length()) longest = temp;
    if (longest.length() > 0){  println(longest);}
    else println("NONE");
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