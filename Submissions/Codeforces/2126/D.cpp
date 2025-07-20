#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  array<int, 3> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  sort(a + 1, a + n + 1);
  int ans = k;
  for (int i = 1; i <= n; i++) {
    auto [l, r, real] = a[i];
    if (l <= ans and ans <= r) ans = max(ans, real);
  }
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