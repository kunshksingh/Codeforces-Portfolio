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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> tables;
    string t;
    cin >> t;

    for (int i = 0; i < n; i++){

        tables.push_back(t[i] - '0');
    }
    int i = 0;
     while (i < n){
        if (tables[i] == 1){
            int j = i;
            int bound = min(n,i+k+1);
            while (j < bound){
                if (tables[j] == 1){
                    bound = min(n, j+k+1);
                }
                tables[j] = 1;
                j++;
            }
            i = j-1;
        }
        i++;
    }
    // for (int i = 0; i < n; i++){

    //     cout << tables[i] << " ";
    // }
    // cout << endl;
    i = n-1;
    while (i >= 0){
        if (tables[i] == 1){
            int j = i;
            int bound = max(0,i-k);
            while ( j >= bound){
                if (tables[j] == 1){
                    bound = max(0,j-k);
                }
                tables[j] = 1;
                j--;
            }
            i = j;
        }
        i--;
    }
    // for (int i = 0; i < n; i++){

    //     cout << tables[i] << " ";
    // }
    // cout << endl;

    int sum = 0;
    i = 0;
     while (i < n){
        if (tables[i] == 0){
            sum += 1;
            i += k;
        }
        i++;
    }
    // cout << endl;
    // int sum = accumulate(tables.begin(), tables.end(), 0);
    cout <<  sum << endl;


    

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