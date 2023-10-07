/**
 *    author:  tourist
 *    created: 07.10.2023 13:15:07       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      x[i] *= 2;
    }
    sort(x.begin(), x.end());
    long long ans = -1;
    if (n != 5) {
      long long a = (x[0] + x[1]) / 2;
      long long b = (x[n - 2] + x[n - 1]) / 2;
      ans = b - a;
    } else {
      long long a = (x[0] + x[2]) / 2;
      long long b = (x[3] + x[4]) / 2;
      ans = max(ans, b - a);
      a = (x[0] + x[1]) / 2;
      b = (x[2] + x[4]) / 2;
      ans = max(ans, b - a);
    }
    cout << ans / 2 << "." << ans % 2 * 5 << '\n';
  }
  return 0;
}
