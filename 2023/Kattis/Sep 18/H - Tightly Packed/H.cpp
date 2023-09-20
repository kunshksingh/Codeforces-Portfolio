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
    long long num; 
    cin >> num;
    long long minimum_squares = num;
    for (long long i = sqrtl(num); i < sqrtl(num)+(sqrtl(num)/2)+1; i++){
        // cout << i << " " <<  ((num + i - 1)/ i) <<endl;
        if(i > 2* ((num + i - 1)/ i)  ){
            break;
        }
        minimum_squares = min(minimum_squares, (i * ((num + i - 1)/ i) - num));
    }
    cout << minimum_squares << endl;
    /*
    def solution():
    N = int(input())

    minimum_squares = N
    for i in range(int(math.sqrt(N)),int(math.sqrt(N))+int(math.sqrt(N))//2+1):
        minimum_squares = min(minimum_squares, (i*((N+i-1)//i) - N))
      
    print(minimum_squares)
    

    */
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