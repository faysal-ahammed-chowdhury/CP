#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int pos_odd_cnt = 0, mn_pos_odd = inf, ans = 0, mx_neg_odd = -inf;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x > 0) {
      if (x & 1) {
        mn_pos_odd = min(mn_pos_odd, x);
        pos_odd_cnt++;
      }
      ans += x;
    }
    else if (x & 1) {
      mx_neg_odd = max(mx_neg_odd, x);
    }
  }

  if (pos_odd_cnt == 0) ans += mx_neg_odd;
  else if (pos_odd_cnt % 2 == 0) {
    ans -= min(mn_pos_odd, abs(mx_neg_odd));
  }

  cout << ans << '\n';

  return 0;
}