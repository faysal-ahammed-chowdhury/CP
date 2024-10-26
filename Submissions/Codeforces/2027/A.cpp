#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  array<int, 2> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][0];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  int ans = 0, x = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(x - a[i][0]);

    if (a[i][1] > mx) {
      ans += abs(mx - a[i][1]);
    }

    mx = max(mx, a[i][1]);
    x = a[i][0];
  }

  ans += x + mx;

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