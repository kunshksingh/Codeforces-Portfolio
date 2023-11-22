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


void solve(){
    int n;
    cin >> n;
    vector<pii> scores;
    string line;
    string part;
    string o_temp;

    while(getline(cin, line)){
        vi temp;
        stringstream ss(line);
        while(getline(ss, part, '-')){
            temp.pb(stoi(part));
        }
        if (sz(temp) == 2) scores.pb(make_pair(temp[0],temp[1]));

    }
    int prev_score = scores[0].first+scores[0].second;
    int curr_score;
    pii curr = make_pair(scores[0].first, scores[0].second);
    int j = n;
    if (curr.first != 11 && curr.second != 11){
        rep(1,n){
            if (scores[i].first > 11 || scores[i].second > 11) {
                println("error "<< (i+1));
                return;
            }
            curr_score = scores[i].first + scores[i].second; 

            if (curr_score == prev_score){
                if (scores[i].first != curr.first || scores[i].second != curr.second){
                    println("error "<< (i+1));
                    return;
                }
                continue;
            }
            if (curr_score > 1 && (curr_score % 4 == 0 ||curr_score % 4 == 2 )){
                if (scores[i].first < curr.first || scores[i].second < curr.second){
                    println("error "<< (i+1));
                    return;
                }
            }
            else{

                 if (scores[i].second < curr.first || scores[i].first < curr.second){
                    println("error "<< (i+1));
                    return;
                }
            }
            curr.first = scores[i].first; 
            curr.second = scores[i].second; 
            prev_score = curr_score;
            if (scores[i].first == 11 || scores[i].second == 11) {j = i; break;};
        }
    }
    else{
        j = 0;
    }
    rep(j,n){
         if (scores[i].first > 11 || scores[i].second > 11) {
                println("error "<< (i+1));
                return;
            }
        if (scores[i].first != curr.first || curr.second != scores[i].second) {
            println("error "<< (i+1));
            return;
        }
    }

    println("ok");
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