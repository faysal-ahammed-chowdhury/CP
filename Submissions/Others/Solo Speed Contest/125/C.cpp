#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long l, r; cin >> l >> r;
  long long ans = (r / 3) - ((l - 1) / 3);
  cout << ans << '\n';
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