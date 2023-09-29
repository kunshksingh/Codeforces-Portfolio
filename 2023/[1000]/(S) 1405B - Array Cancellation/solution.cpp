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
    long long coins = 0;
    long long n = 0;
    long long val;
    vector<long long> vec;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> val;
        vec.push_back(val);
    }   
    long long i = 0;
    long long j = 0;
    // long long k = 0;


    while (i < vec.size()){
        if (vec[i] > 0){
            break;
        }
        i++;
    }
    while (j < vec.size()){
        if (vec[j] < 0){
            break;
        }
        j++;
    }
    // while (k < vec.size()){
    //     if (vec[k] < 0){
    //         break;
    //     }
    //     k++;
    // }

    while (i < vec.size()){
    
        if (vec[i] == 0){
            while (i < vec.size()){
                if (vec[i] > 0){
                    break;
                }
                i++;
            }

               
        }
        if (vec[j] == 0){
            while (j < vec.size()){
                if (vec[j] < 0){
                    break;
                }
                j++;
            }

        }
        // if (vec[k] == 0){
        //     while (k < vec.size()){
        //         if (vec[k] < 0){
        //             break;
        //         }
        //         k++;
        //     }

        // }
         if (j < i){
            j = i + 1;
            while (j < vec.size()){
                // cout << "j " << j << endl;
                if (vec[j] < 0){
                    break;
                }
                j++;
            }
        }
        if (j >= vec.size()){
            // j = k;
            break;
        }

        if (i >= vec.size()){
            break;
        }
        long long temp = min(abs(vec[i]), abs(vec[j]));
        if (i < j){
            vec[i] -= temp;
            vec[j] += temp;
        }
        else {
            vec[i] -= temp;
            vec[j] += temp;
            coins += temp;
        }
    }   
    for (int i: vec){
        if (i > 0){
            coins += i;
        }
    }
    cout << coins << endl;
    

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