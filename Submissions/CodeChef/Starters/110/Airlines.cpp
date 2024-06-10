#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, n; cin >> x >> n;
  int rem = n - (x * 100);
  int ans = rem <= 0 ? 0 : (rem + 99) / 100;
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