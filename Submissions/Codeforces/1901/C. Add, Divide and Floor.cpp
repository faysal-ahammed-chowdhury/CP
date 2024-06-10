#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

void solve() {
  int n; cin >> n;
  int a[n + 1], mx = -inf, mn = inf;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }

  vector<int> ans;
  while (mx != mn) {
    ans.push_back(mx + 1);
    mn = (mn + mx + 1) / 2;
    mx = (mx + mx + 1) / 2;
  }

  cout << ans.size() << '\n';
  if (ans.size() <= n) {
    for (auto x : ans) {
      cout << x << ' ';
    }
    if (ans.size() != 0) cout << '\n';
  }
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