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
    long long n;
    cin >> n;
    vector<long long> nums;
    for (long long i = 0; i < n; i++){
        long long val;
        cin >> val;
        long long temp = (val-i)-1;
        nums.push_back(temp);
      
    
    }
    long long goodArrs = 0; 
    long long fastPtr = 0;
    for (long long i = 0; i < n; i ++){
        while (fastPtr < n && (nums[fastPtr]+i) >= 0){
            fastPtr += 1;
        }
        if (fastPtr+1 == n && (nums[fastPtr]+i) >= 0){
            fastPtr+=1;
        }

        goodArrs += (fastPtr - i); 
    }

    cout << goodArrs << endl;
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