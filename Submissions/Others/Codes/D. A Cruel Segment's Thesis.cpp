#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;

void solve() {
  int n; cin >> n;
  ll ans = 0;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    ans += (r - l);
    ans += r;
    v.push_back({l + r, r});
  }
  sort(v.begin(), v.end());

  ll pref[n];
  for (int i = 0; i < n; i++) {
    pref[i] = (i > 0 ? pref[i - 1] : 0) + v[i].first;
    // cout << pref[i] << ' ';
  }
  // cout << '\n';

  if (n % 2 == 0) {
    ll tmp = (n / 2) - 1 >= 0 ? pref[(n / 2) - 1] : 0;
    ans -= tmp;
    cout << ans << '\n';
    return;
  }

  ll mn = inf;
  for (int i = 0; i < n; i++) {
    if (i >= (n / 2)) {
      ll tmp = (n / 2) - 1 >= 0 ? pref[(n / 2) - 1] : 0;
      tmp += v[i].second;
      mn = min(mn, tmp);
    }
    else {
      ll tmp = pref[(n / 2)];
      tmp -= v[i].first;
      tmp += v[i].second;
      mn = min(mn, tmp);
    }
  }

  ans -= mn;
  // cout << mn << '\n';
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}