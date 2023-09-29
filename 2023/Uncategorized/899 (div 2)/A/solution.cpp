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

// def solution():
//     n = int(input())
//     s_0, e_0 = map(int, input().split())
//     for i in range(1,n):
//         s_i, e_i = map(int, input().split())
//         if (s_0 <= s_i and e_0 <= e_i):
//             print(-1)
//             return
//     print(s_0)

void solve(){
    int n;
    string line;
    cin >> n;
    int s_0, s_i, e_0, e_i;

    cin >> s_0 >> e_0;
    bool vool = false;
    for (int i = 1; i < n; i++){
        cin >> s_i >> e_i;
        if (vool){
            continue;
        }
        if (s_0 <= s_i && e_0 <= e_i){
            cout << -1 << endl;
            vool = true;
        }
    }
    if (vool){
        return;
    }
    cout << s_0 << endl;
    
    
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

// import sys
// import math
// import heapq
// import collections
// # import numpy as np
// # from numpy.fft import fft, ifft

// input = sys.stdin.readline # Don't forget to rstrip()

// testcases = int(input())
// def solution():
//     n = int(input())
//     s_0, e_0 = map(int, input().split())
//     for i in range(1,n):
//         s_i, e_i = map(int, input().split())
//         if (s_0 <= s_i and e_0 <= e_i):
//             print(-1)
//             return
//     print(s_0)


// for i in range(testcases):
//     solution()