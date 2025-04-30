#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, x; cin >> n >> x;
  int diff = -1, mx = 0;
  for (int i = 1; i <= n; i++) {
    int d, h; cin >> d >> h;
    diff = max(diff, d - h);
    mx = max(mx, d);
  }
  if (x <= mx) {
    cout << 1 << '\n';
    return;
  }
  if (diff <= 0) {
    cout << -1 << '\n';
    return;
  }
  int ans = 1;
  x -= mx;
  ans += (x + diff - 1) / diff;
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