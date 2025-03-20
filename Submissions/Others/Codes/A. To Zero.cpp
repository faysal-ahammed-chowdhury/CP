#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int x = k - 1;
  int ans = 0;
  if (n % 2 == 1) {
    ans++;
    n -= k;
    n = max(n, 0);
  }

  ans += n / x;
  n %= x;

  if (n > 0) ans++;

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