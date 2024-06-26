#include <bits/stdc++.h>
using namespace std;

#define int long long

void fix(int &x, int y) {
  while (x % y == 0) x /= y;
}

void solve() {
  int x, y, k; cin >> x >> y >> k;
  while (true) {
    if (x < y) {
      k %= (y - 1);
    }
    int need = y - (x % y);
    if (k < need) {
      x += k;
      break;
    }
    else {
      x += need;
      k -= need;
      fix(x, y);
    }
  }
  cout << x << '\n';
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