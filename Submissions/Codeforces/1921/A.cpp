#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x1, y1; cin >> x1 >> y1;
  int x2, y2; cin >> x2 >> y2;
  int x3, y3; cin >> x3 >> y3;
  int x4, y4; cin >> x4 >> y4;

  int x = abs(x1 - x2);
  if (x == 0) {
    x = abs(x1 - x3);
  }
  if (x == 0) {
    x = abs(x1 - x4);
  }
  int y = abs(y1 - y2);
  if (y == 0) {
    y = abs(y1 - y3);
  }
  if (y == 0) {
    y = abs(y1 - y4);
  }

  cout << x * y << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}