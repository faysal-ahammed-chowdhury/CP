#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    while (k--) {
      int x; cin >> x;
      a[i].push_back(x);
      mp[x]++;
    }
  }

  bool ok = true;
  for (int i = 1; i <= m; i++) {
    ok &= mp[i] >= 1;
  }

  if (!ok) {
    cout << "NO\n";
    return;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (auto x : a[i]) {
      ok &= mp[x] >= 2;
    }
    if (ok) cnt++;
  }

  if (cnt >= 2) cout << "YES\n";
  else cout << "NO\n";
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