#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int x, y; cin >> x >> y;
  for (int k = 0; k < 30; k++) {
    if (CHECK(x, k) != CHECK(y, k)) {
      cout << (1 << k) << '\n';
      return;
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