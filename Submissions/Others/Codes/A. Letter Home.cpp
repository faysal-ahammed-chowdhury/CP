#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, pos; cin >> n >> pos;
  int mn = 105, mx = -105;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
  }

  if (pos <= mn) {
    cout << mx - pos << '\n';
  }
  else if (pos >= mx) {
    cout << pos - mn << '\n';
  }
  else {
    int d1 = abs(pos - mn);
    int d2 = abs(pos - mx);
    int ans = min(d1, d2) + (mx - mn);
    cout << ans << '\n';
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