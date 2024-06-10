#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll a, b, r; cin >> a >> b >> r;
  if (a == b) {
    cout << 0 << '\n';
    return;
  }
  int zero_kar, idx;
  for (int k = 59; k >= 0; k--) {
    if ((a & (1ll << k)) != (b & (1ll << k))) {
      if ((a & (1ll << k))) {
        zero_kar = 2;
      }
      else {
        zero_kar = 1;
      }
      idx = k;
      break;
    }
  }

  ll ans = (1ll << idx);

  vector<int> v;
  for (int k = idx - 1; k >= 0; k--) {
    if ((a & (1ll << k)) != (b & (1ll << k))) {
      if (zero_kar == 1) {
        if ((b & (1ll << k))) {
          v.push_back(k);
        }
        else {
          ans -= (1ll << k);
        }
      }
      else if (zero_kar == 2) {
        if ((a & (1ll << k))) {
          v.push_back(k);
        }
        else {
          ans -= (1ll << k);
        }
      }
    }
  }

  for (auto x : v) {
    if (r >= (1ll << x)) {
      r -= (1ll << x);
      ans -= (1ll << x);
    }
    else {
      ans += (1ll << x);
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}