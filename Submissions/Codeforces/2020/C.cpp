#include <bits/stdc++.h>
using namespace std;

#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

void solve() {
  int b, c, d; cin >> b >> c >> d;
  int a = 0;
  for (int k = 0; k < 61; k++) {
    if (CHECK(c, k) and CHECK(d, k)) {
      if (CHECK(b, k) == false) {
        cout << -1 << '\n';
        return;
      }
      continue;
    }
    if (CHECK(c, k) == false and CHECK(d, k) == false) {
      if (CHECK(b, k)) {
        cout << -1 << '\n';
        return;
      }
      continue;
    }
    SET(a, k);
  }
  // cout << ((a | b) - (a & c)) << ' ';
  cout << a << '\n';
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