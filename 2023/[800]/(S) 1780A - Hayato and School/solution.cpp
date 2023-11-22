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
    vi a(n);
    rep2(n) cin >> a[i];
    if (n == 3){
        int x = a[0] + a[1] + a[2];
        if (x % 2 == 1){ println("YES"); println(1 << " " <<  2 << " " << 3)}
        else println("NO");
        return;
    }
    rep2(n) {
        if (a[i] % 2 != 0){
            println("YES");
            if (i >= 2){
                println(1 << " " << 2 << " " << (i+1));
            }else{
                int s, j;
                if (i == 0){
                    s = a[1];
                    j = 1;
                }
                else{
                    s = a[0];
                    j = 0;
                }
                if (a[j]%2 == a[2]%2){
                    println((i+1) << " " << (j+1) << " " << 3);
                } else if (a[j]%2 == a[3]%2){
                    println((i+1) << " " << (j+1) << " " << 4);
                }else{
                    println((i+1) << " " << 3 << " " << 4);
                }
            }
            return;
        }
    }
    println("NO");
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