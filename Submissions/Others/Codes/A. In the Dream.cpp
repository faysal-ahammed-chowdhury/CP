#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ok(int a, int b) {
  int x = min(a, b);
  int y = max(a, b);
  return y <= x * 2 + 2;
}

void solve() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  if (ok(a, b) and ok(c - a, d - b)) cout << "YES\n";
  else cout << "NO\n";
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