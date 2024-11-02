#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l, r; cin >> l >> r;
  int start = (l % 2 == 0 ? l : l + 3);
  int cnt = 0, tot = r - l + 1;
  for (int i = start; i <= r; i += 4) {
    cnt++;
  }
  int ans = (tot - cnt) / 3;
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