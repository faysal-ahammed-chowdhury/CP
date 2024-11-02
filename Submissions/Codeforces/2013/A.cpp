#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n, x, y; cin >> n >> x >> y;
  int mn = min(x, y);
  int ans = (n + mn - 1) / mn;
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