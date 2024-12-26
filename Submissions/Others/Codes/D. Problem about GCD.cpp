#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll a, b, g; cin >> a >> b >> g;

  ll x = a % g;
  ll l = a + g - (x == 0 ? g : x);
  ll r = b - (b % g);
  // cout << l << ' ' << r << '\n';

  if (l > b or r < a) {
    cout << -1 << ' ' << -1 << '\n';
    return;
  }

  int k = 60;
  ll dis = -1, ans1 = -1, ans2 = -1;
  for (ll j = r, jj = 1; j >= l and jj <= k; j -= g, jj++) {
    for (ll i = l, ii = 1; i <= r and ii <= k; i += g, ii++) {
      ll here = gcd(i, j);
      if (here == g) {
        if (abs(i - j) >= dis) {
          dis = abs(i - j);
          ans1 = i, ans2 = j;
        }
      }
    }
  }
  if (dis == -1 or !(ans1 >= a and ans1 <= b and ans2 >= a and ans2 <= b)) cout << -1 << ' ' << -1 << '\n';
  else cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << '\n';
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