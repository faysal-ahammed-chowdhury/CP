#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, d, a; cin >> n >> d >> a;

  if (d == 0) {
    cout << ((a + 2) < n ? -1 : (a < n ? n - 1 : n)) << '\n';
    return;
  }

  int cnt = max(0ll, ((n - 1) - a)) / d;
  cnt++;
  int cur = (a + (cnt - 1) * d);
  if (cur >= n) cnt--;

  int ans = n - cnt;
  ans = max(ans, 0ll);
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