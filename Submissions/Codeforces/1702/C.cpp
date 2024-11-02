#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  map<int, int> first, last;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (first.find(a[i]) == first.end()) {
      first[a[i]] = i;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (last.find(a[i]) == last.end()) {
      last[a[i]] = i;
    }
  }
  while (q--) {
    int u, v; cin >> u >> v;
    if (first.find(u) == first.end()) cout << "NO\n";
    else if (first[u] <= last[v]) cout << "YES\n";
    else cout << "NO\n";
  }
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