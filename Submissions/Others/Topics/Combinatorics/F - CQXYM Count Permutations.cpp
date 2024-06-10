#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  n *= 2;
  int ans = 1;
  for (int i = 3; i <= n; i++) {
    ans = 1ll * ans * i % mod;
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