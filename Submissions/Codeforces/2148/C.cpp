#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m; cin >> n >> m;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);

  int cur = 0, ans = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    int d = a[i].first - last;
    if (d & 1) cur ^= 1;
    ans += d;
    if (cur != a[i].second) {
      cur ^= 1;
      ans--;
    }
    last = a[i].first;
  }

  ans += (m - last);

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