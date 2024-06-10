#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int n, m; cin >> n >> m;
  int x = n ^ m;

  bool ok = false;
  for (int k = 30; k >= 0; k--) {
    if (ok and CHECK(x, k)) {
      x -= (1 << k);
    }
    else if (!CHECK(m, k) and CHECK(n, k)) {
      ok = true;
      x -= (1 << k);
    }
  }

  if (ok) {
    cout << x << '\n';
    return;
  }

  for (int k = 0; k <= 30; k++) {
    if (!CHECK(m, k) and !CHECK(n, k)) {
      x += (1 << k);
      cout << x << '\n';
      return;
    }
    else {
      if (CHECK(x, k)) {
        x -= (1 << k);
      }
    }
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