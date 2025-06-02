#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  ll time = 0;
  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    int idx = (i + 1) / 2;
    if (i % 2 == 0) idx = -idx;
    ans[a[i].second] = idx;
    time += 1ll * a[i].first * 2 * abs(idx);
  }
  cout << time << '\n';
  cout << 0 << ' ';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}