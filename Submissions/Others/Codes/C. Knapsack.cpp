#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; ll mx; cin >> n >> mx;
  ll mn = (mx + 1) / 2;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x <= mx) {
      v.push_back({x, i});
    }
  }

  sort(v.rbegin(), v.rend());
  vector<int> ans;
  ll sum = 0;
  for (int i = 0; i < v.size(); i++) {
    if (sum + v[i].first <= mx) {
      sum += v[i].first;
      ans.push_back(v[i].second);
    }
    if (sum >= mn) {
      sort(ans.begin(), ans.end());

      cout << ans.size() << '\n';
      for (auto x : ans) {
        cout << x << ' ';
      }
      cout << '\n';
      return;
    }
  }

  cout << -1 << '\n';
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