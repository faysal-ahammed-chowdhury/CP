#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  vector<array<int, 2>> a[n + 1];
  while (q--) {
    int x, l, r; cin >> x >> l >> r;
    a[x].push_back({r, l});
  }

  int cnt = 0, idx = -1;
  for (int i = 1; i <= n; i++) {
    sort(a[i].begin(), a[i].end());
    int last = 0, here = 0;
    for (auto [r, l] : a[i]) {
      if (l <= last) {
        here++;
        idx = i;
      }
      last = r;
    }
    cnt += here > 0;
  }

  if (cnt == 0) {
    cout << "YES\n";
    return;
  }

  if (cnt >= 2) {
    cout << "NO\n";
    return;
  }

  sort(a[idx].begin(), a[idx].end());

  for (int j = 0; j < a[idx].size(); j++) {
    int last = 0, here = 0;
    for (int i = 0; i < a[idx].size(); i++) {
      if (i == j) continue;
      auto [r, l] = a[idx][i];
      if (l <= last) {
        here++;
      }
      last = r;
    }
    if (here == 0) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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