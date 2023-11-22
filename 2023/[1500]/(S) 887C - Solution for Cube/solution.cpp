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

vi rotate(vi &a, vi &nums){
    vi b(24);
    rep2(24) b[i] = a[i];
    int m = -1;
    int temp = 0;
    for (int n : nums){
        if (m == -1) {
            m = b[n];
            continue;
        }
        swap(b[n],m); 
    }
    b[nums[0]] = m;
    temp = 0;
    m = -1;
    for (int n : nums){
        if (m == -1) {
            m = b[n];
            continue;
        }
        swap(b[n],m); 
    }
    b[nums[0]] = m;
    return b;
}

bool solve(){
    vi cube(24);
    vector<vector<int>> rot;
    rep2(24) cin >> cube[i];
    rep2(12) rot.pb(cube);
    vi rot1 = {1,3,5,7,9,11,20,22};
    vi rot2 = {0,2,4,6,8,10,21,23};
    vi rot3 = {8,9,18,16,3,2,13,15};
    vi rot4 = {10,11,19,17,1,0,12,14}; 
    vi rot5 = {12, 13, 4, 5, 16, 17, 20, 21};
    vi rot6 = {14, 15, 6, 7, 18, 19, 22, 23};
    vi rot7 = {1,3,5,7,9,11,20,22};
    vi rot8 = {0,2,4,6,8,10,21,23};
    vi rot9 = {8,9,18,16,3,2,13,15};
    vi rot10 = {10,11,19,17,1,0,12,14}; 
    vi rot11 = {12, 13, 4, 5, 16, 17, 20, 21};
    vi rot12 = {14, 15, 6, 7, 18, 19, 22, 23};

    reverse(rot7.begin(),rot7.end());
    reverse(rot8.begin(),rot7.end());
    reverse(rot9.begin(),rot7.end());
    reverse(rot10.begin(),rot7.end());
    reverse(rot11.begin(),rot7.end());
    reverse(rot12.begin(),rot7.end());

    rot[0] = rotate(cube, rot1); 
    rot[1] = rotate(cube, rot2); 
    rot[2] = rotate(cube, rot3); 
    rot[3] = rotate(cube, rot4); 
    rot[4] = rotate(cube, rot5); 
    rot[5] = rotate(cube, rot6); 
    rot[6] = rotate(cube, rot7); 
    rot[7] = rotate(cube, rot8); 
    rot[8] = rotate(cube, rot9); 
    rot[9] = rotate(cube, rot10); 
    rot[10] = rotate(cube, rot11); 
    rot[11] = rotate(cube, rot12); 

    bool flag;
    
    for (int i = 0; i < 12; i++){
        flag = true;
        for (int j = 0; j < 24; j+=4){
            if (!(rot[i][j] == rot[i][j+1] && rot[i][j+1] == rot[i][j+2] && rot[i][j+2] == rot[i][j+3])) flag = false;
        }
        if (flag) return true;
    }
    
    return false;
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
        
        if (solve()) {println("YES");}
        else{ println("NO");}
    }
}