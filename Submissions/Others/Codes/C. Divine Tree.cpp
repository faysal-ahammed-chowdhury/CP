#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n, m; cin >> n >> m;
  ll org_m = m;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }

  vector<int> ans;
  int rem = n - 1;
  while (true) {
    ll mx = m - rem;
    if (!se.empty()) mx = min(mx, 1ll * *(--se.end()));
    auto it = se.upper_bound(mx);
    if (it == se.begin()) break;
    --it;
    int val = *it;
    se.erase(val);
    ans.push_back(val);
    m -= val;

    rem--;
  }

  for (auto x : se) {
    ans.push_back(x);
  }

  ll tmp = 0;
  int mn = n + 1;
  for (auto x : ans) {
    mn = min(mn, x);
    tmp += mn;
  }

  if (tmp == org_m) {
    cout << ans.front() << '\n';
    for (int i = 1; i < ans.size(); i++) {
      cout << ans[i - 1] << ' ' << ans[i] << '\n';
    }
  }
  else cout << -1 << '\n';
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