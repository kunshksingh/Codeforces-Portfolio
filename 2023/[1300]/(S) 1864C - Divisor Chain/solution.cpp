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

void solve(vector<long long> &twos){
    long long k;
    vector<int> sols;
    cin >> k;
    sols.push_back(k);
    if (k % 2 == 1){
        sols.push_back(k-1);
        k -= 1;
    }
    string bin_k = bitset<32>(k).to_string();
    reverse(bin_k.begin(), bin_k.end());
    
    int n = bin_k.length();
    int j;
    
    for (int i = 1; i <n; i++){
        if ((find(twos.begin(), twos.end(), k) != twos.end())){
            j = find(twos.begin(), twos.end(), k) - twos.begin();
            break;
        }
        if (bin_k[i] == '1'){
            k = k-twos[i];
            sols.push_back(k);
        }
    }
    while (j > 0){
        k -= twos[j-1];
        sols.push_back(k);
        j--;
    }
    // reverse(sols.begin(),sols.end())
    cout << sols.size() << endl;
    for (int i : sols){
        cout << i << " ";
    } 
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    vector<long long> twos;
    twos.push_back(1);
    for (long long i = 1; i < 64; i++){
        twos.push_back(2*twos[i-1]);
    }
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve(twos);
    }
    
}