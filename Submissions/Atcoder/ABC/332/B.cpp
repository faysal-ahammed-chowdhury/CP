#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k, g, m; cin >> k >> g >> m;
  int cur_g = 0, cur_m = 0;

  while (k--) {
    if (cur_g == g) {
      cur_g = 0;
    }
    else if (cur_m == 0) {
      cur_m = m;
    }
    else {
      int need = g - cur_g;
      int x = min(need, cur_m);
      cur_g += x, cur_m -= x;
    }
  }

  cout << cur_g << ' ' << cur_m << '\n';

  return 0;
}