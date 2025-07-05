#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  vector<pair<int, int>> v;
  int idx = 0;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int c, x; cin >> c >> x;
      v.push_back({c, x});
    }
    else {
      int k; cin >> k;
      ll ans = 0;
      while (true) {
        auto &[c, x] = v[idx];
        if (c > k) {
          ans += 1ll * k * x;
          c -= k;
          break;
        }
        ans += 1ll * c * x;
        k -= c;
        idx++;
        if (k == 0) break;
      }
      cout << ans << '\n';
    }
  } 

  return 0;
}