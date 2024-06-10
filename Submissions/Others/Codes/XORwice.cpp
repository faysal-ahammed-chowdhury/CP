#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int a, b; cin >> a >> b;
  int ans = 0;
  for (int k = 0; k < 30; k++) {
    if (CHECK(a, k) != CHECK(b, k)) {
      ans |= (1 << k);
    }
  }
  cout << ans << '\n';
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