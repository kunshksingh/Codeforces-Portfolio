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
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    if(n==5){
        double mid1 = (double)(arr[0] + arr[1])/2;
        double mid2 = (double)(arr[n-1] + arr[n-3])/2;
        double ans1 = mid2-mid1;
        mid1 = (double)(arr[0] + arr[2])/2;
        mid2 = (double)(arr[n-1] + arr[n-2])/2;
        double ans2 = mid2-mid1;
        cout<<max(ans1,ans2)<<"\n";
        return;
    }
    double mid1 = (double)(arr[0] + arr[1])/2;
    double mid2 = (double)(arr[n-1] + arr[n-2])/2;
    cout<<mid2-mid1<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        cout<<"Case #"<<c+1<<": ";
        solve();
    }
}