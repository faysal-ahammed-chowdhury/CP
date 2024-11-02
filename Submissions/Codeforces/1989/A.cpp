#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y; cin >> x >> y;
  x = abs(x);
  int nambe = (x - 1);
  int yy = y;
  if (y > 0) {
    yy = max(yy - nambe, 0);
    nambe -= (y - yy);
  }
  yy -= nambe;
  if (-x <= (yy)) cout << "YES\n";
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