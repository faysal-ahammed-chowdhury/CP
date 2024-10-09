#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int l, n; cin >> l >> n;
  int mn = 1e10, mx = 0;
  int ans1 = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
    ans1 = max(ans1, min(x, l - x));
  }
  int ans2 = max(mx, l - mn);
  cout << ans1 << ' ' << ans2 << '\n';
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