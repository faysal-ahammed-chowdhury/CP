#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y; cin >> x >> y;
  if (x + 1 == y) cout << "YES\n";
  else if (x > y) {
    int d = x - y;
    if (d % 9 == 8) cout << "YES\n";
    else cout << "NO\n";
  }
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