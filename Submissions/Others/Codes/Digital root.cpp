#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll k, x; cin >> k >> x;
  ll ans = x + (9 * (k - 1));
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