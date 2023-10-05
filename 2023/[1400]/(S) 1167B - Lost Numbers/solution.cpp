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
    int a12, a24, a25, a66;
    cout << "? " << 1 << " " << 2 << endl;
    cin >> a12;
    cout << "? " << 2 << " " << 4 << endl;
    cin >> a24;
    cout << "? " << 2 << " " << 5 << endl;
    cin >> a25;
    cout << "? " << 6 << " " << 6 << endl;
    cin >> a66;

    int a1,a2,a3,a4,a5,a6;
    a2 = 1;
    vi sNums { 4, 8, 15, 16, 23, 42 };
    reverse(sNums.begin(), sNums.end());
    for(int i:sNums){
        if(a12 % i == 0 && a24 % i == 0 && a25 % i == 0){
            a2 = i;
            break;
        }
    }
    a1 = a12 / a2;
    a4 = a24 / a2;
    a5 = a25 / a2;
    a6 = sqrt(a66);
    for (int i: sNums) if (a1 != i && a2 != i && a4 != i && a5 != i && a6 != i) a3 = i;
    cout << "! " <<a1 << " "<< a2 << " "<< a3 << " " << a4 << " " <<a5 << " "<< a6 << endl;

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