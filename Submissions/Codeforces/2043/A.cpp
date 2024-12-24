#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n;
  int cnt = 0;
  while (n > 3) {
    cnt++;
    n /= 4;
  }

  ll ans = (1ll << cnt);
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