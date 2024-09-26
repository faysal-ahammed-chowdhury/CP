#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      int x, y, z; cin >> x >> y >> z;
      ok &= x == 2;
      ok &= y == 3;
      ok &= z == 10;
    }
    int x, y, z; cin >> x >> y >> z;
    ok &= x == 1;
    ok &= y == 3;
    ok &= z == 10;
    cin >> x >> y >> z;
    ok &= x == 3;
    ok &= y == 3;
    ok &= z == 10;
  }
  if (ok) cout << "Consistent\n";
  else cout << "Inconsistent\n";
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