#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> se;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (i != 1) {
      if (se.find(x + 1) == se.end() and se.find(x - 1) == se.end()) ok = false;
    }
    se.insert(x);
  }
  if (ok) cout << "YES\n";
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