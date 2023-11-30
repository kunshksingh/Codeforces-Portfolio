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
    vector<string> guy1(n);
    vector<string> guy2(n);
    vector<string> guy3(n);
    rep2(n) cin >> guy1[i];
    rep2(n) cin >> guy2[i];
    rep2(n) cin >> guy3[i];

    set<string> words;
    set<string> words2;
    set<string> words3;
    rep2(n){
        if (find(words2.begin(), words2.end(), guy1[i]) != words2.end()) words3.insert(guy1[i]);
        else if ((find(words.begin(), words.end(), guy1[i]) != words.end())) words2.insert(guy1[i]);
        else words.insert(guy1[i]);
        if (find(words2.begin(), words2.end(), guy2[i]) != words2.end()) words3.insert(guy2[i]);
        else if ((find(words.begin(), words.end(), guy2[i]) != words.end())) words2.insert(guy2[i]);
        else words.insert(guy2[i]);
        if (find(words2.begin(), words2.end(), guy3[i]) != words2.end()) words3.insert(guy3[i]);
        else if ((find(words.begin(), words.end(), guy3[i]) != words.end())) words2.insert(guy3[i]);
        else words.insert(guy3[i]);
    }
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    rep2(n){
        if (find(words3.begin(), words3.end(), guy1[i]) != words3.end()) ;
        else if ((find(words2.begin(), words2.end(), guy1[i]) != words2.end())) g1++;
        else g1+=3;
        if (find(words3.begin(), words3.end(), guy2[i]) != words3.end()) ;
        else if ((find(words2.begin(), words2.end(), guy2[i]) != words2.end())) g2++;
        else g2+=3;
        if (find(words3.begin(), words3.end(), guy3[i]) != words3.end()) ;
        else if ((find(words2.begin(), words2.end(), guy3[i]) != words2.end())) g3++;
        else g3+=3;
    }
    print(g1);
    print(g2);
    print(g3);
    println("");
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