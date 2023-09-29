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
/*
auto pr = std::max_element
(
    std::begin(frequencyCount), std::end(frequencyCount),
    [] (const pair_type & p1, const pair_type & p2) {
        return p1.second < p2.second;
    }
);
*/

void solve(){
    int n, val;
    int maximum;
    cin >> n;
    map<string, int> dice_seq;
    for (int i = 0; i < n; i++){
        vector<int> dice;
        for (int j = 0; j < 6; j++){
            cin >> val;
            dice.push_back(val);
        }
        dice.push_back(dice[0]);
        dice.push_back(dice[1]);
        dice.push_back(dice[2]);
        dice.push_back(dice[3]);
        dice.push_back(dice[4]);
        set<string> dice_seq_tried;
        for (int j = 0; j < 5; j++){
            if (dice_seq_tried.find((to_string(dice[j])+to_string(dice[j+2])+to_string(dice[j+3])+to_string(dice[j+4])+to_string(dice[j+5]))) != dice_seq_tried.end()){
                continue;
            }
            dice_seq[(to_string(dice[j])+to_string(dice[j+2])+to_string(dice[j+3])+to_string(dice[j+4])+to_string(dice[j+5]))] += 1;
            dice_seq_tried.insert((to_string(dice[j])+to_string(dice[j+2])+to_string(dice[j+3])+to_string(dice[j+4])+to_string(dice[j+5])));
        }

    }
    map<string,int>::iterator best
        = max_element(dice_seq.begin(),dice_seq.end(),[] (const std::pair<string,int>& a, const std::pair<string,int>& b)->bool{ return a.second < b.second; } );
    
        cout << best -> first << " "<< best -> second << endl;

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