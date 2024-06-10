#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  bool up = false, down = false, right = false, left = false;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    if (x < 0) left = true;
    else if ( x > 0) right = true;
    if (y < 0) down = true;
    else if (y > 0) up = true;
  }
  if (up == false or down == false or right == false or left == false) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
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