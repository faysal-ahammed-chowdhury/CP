#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
ll dp[65][65][65];

ll f(int i, int pw1, int pw2) {
  if (i > 60) return (pw1 == 0 and pw2 == 0) ? 0 : inf;
  ll &ans = dp[i][pw1][pw2];
  if (ans != -1) return ans;
  ans = f(i + 1, pw1, pw2);
  if (i <= pw1) {
    ans = min(ans, (1ll << i) + f(i + 1, pw1 - i, pw2));
  }
  if (i <= pw2) {
    ans = min(ans, (1ll << i) + f(i + 1, pw1, pw2 - i));
  }
  return ans;
}

void solve() {
  ll x, y; cin >> x >> y;
  if (x == y) {
    cout << 0 << '\n';
    return;
  }
  if (x > y) swap(x, y);
  ll ans = inf;
  for (int i = 0; i <= 60; i++) {
    ll xx = x / (1ll << i);
    ll yy, j;
    if (xx == 0) {
      j = __lg(y) + 1;
    }
    else {
      yy = y / xx;
      j = __lg(yy);
    }
    yy = y / (1ll << j);
    // cout << i << ' ' << yy << ' ' << j << '\n';
    if (xx == yy) ans = min(ans, f(1, i, j));
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}