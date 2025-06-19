#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<array<int, 3>> ans;
  for (int i = 1; i <= n; i++) {
    if (i > 1) ans.push_back({i, 1, i});
    if (i + 1 < n) ans.push_back({i, i + 1, n});
  }

  cout << ans.size() << '\n';
  for (auto [i, l, r] : ans) {
    cout << i << ' ' << l << ' ' << r << '\n';
  }
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