#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  for (auto [x, cnt] : mp) {
    if (cnt > 1) {
      cout << 1 << '\n';
      cout << x << '\n';
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