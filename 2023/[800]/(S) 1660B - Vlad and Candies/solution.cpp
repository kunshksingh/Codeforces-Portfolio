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
    int n;
    cin >> n;
    vi a(n);
    rep2(n) cin >> a[i];
    if (n == 1){
        if (a[0] > 1) return false;
        else return true;
    }
    ll acum = accumulate(a.begin(), a.end(), 0LL);
    ll maximum = max(a[0], a[1]);
    ll secondMax = min(a[0], a[1]); 
    rep(2,n){
        if (a[i] >= maximum){
            secondMax = maximum;
            maximum = a[i];
        }
        else if (a[i] >= secondMax){
            secondMax = a[i];
        }
    }
    if (maximum > ((acum+1)/2)){
        return false;
    }
    if (maximum - secondMax > 1) return false;
 
    return true;

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
        if (solve()){
            println("YES");
        }
        else{
            println("NO");
        }
    }
}