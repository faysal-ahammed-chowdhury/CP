#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m, r, c; cin >> n >> m >> r >> c;
  int cnt = n - r;
  int x = m - 1;
  int ans = m - c;
  ans += cnt;
  ans += cnt * x;
  ans += cnt * (m - 1);
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