#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  pair<int, int> x1, x2, y1, y2;
  x1 = y1 = {2e9, 2e9};
  x2 = y2 = {-1, -1};
  for (int i = 1; i <= n; i++) {
    x1 = min(x1, a[i]);
    x2 = max(x2, a[i]);

    if (y1.second > a[i].second) y1 = a[i];
    if (y2.second < a[i].second) y2 = a[i];
  }

  // cout << x1.first << ' ' << x1.second << '\n';
  // cout << x2.first << ' ' << x2.second << '\n';
  // cout << y1.first << ' ' << y1.second << '\n';
  // cout << y2.first << ' ' << y2.second << '\n';

  vector<pair<int, int>> v = {x1, x2, y1, y2};
  // vector<pair<int, int>> v = {y2};

  ll ans = 1e18 + 100;
  for (auto p : v) {
    // cout << p.first << ' ' << p.second << '\n';
    int top = 2e9, left = 2e9;
    int bottom = -1, right = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == p) continue;
      top = min(top, a[i].second);
      left = min(left, a[i].first);
      bottom = max(bottom, a[i].second);
      right = max(right, a[i].first);
    }


    int h = abs(bottom - top) + 1;
    int w = abs(left - right) + 1;
    // cout << h << ' ' << w << '\n';

    ll cnt = 1ll * h * w;
    if (cnt >= n) ans = min(ans, cnt);
    else {
      ans = min(ans, (1ll * (h + 1) * w));
      ans = min(ans, (1ll * h * (w + 1)));
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}