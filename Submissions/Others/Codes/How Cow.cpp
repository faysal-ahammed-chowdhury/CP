#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int m; cin >> m;
  cout << "Case " << ++cs << ":\n";
  while (m--) {
    int x, y; cin >> x >> y;
    if (x >= x1 and x <= x2 and y >= y1 and y <= y2) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
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