#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, c; cin >> n >> c;
  int a[n + 1], even = 0, odd = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    even += a[i] % 2 == 0;
    odd += a[i] % 2;
  }
  ll ans = 1ll * (c + 1) * (c + 2) / 2;
  for (int i = 1; i <= n; i++) {
    ans -= (a[i] / 2) + 1;
    ans -= c - a[i] + 1;
  }

  ans += (1ll * even * (even + 1)) / 2 + (1ll * odd * (odd + 1)) / 2;
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