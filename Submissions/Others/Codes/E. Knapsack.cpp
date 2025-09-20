#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll w, a[10], dp[10][1000];

ll f(int i, ll w) {
  if (i > 8) return 0;
  ll &ans = dp[i][w];
  if (ans != -1) return ans;
  ans = 0;
  for (ll take = 0; take <= min(25ll, a[i]); take++) {
    if (take * i <= w) {
      ans = max(ans, take * i + f(i + 1, w - (take * i)));
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> w;
  ll copy_w = w;
  for (int i = 1; i <= 8; i++) {
    cin >> a[i];
  }

  ll sum = 0;
  for (int i = 8; i >= 1; i--) {
    ll mx = w / i;
    ll take = max(0ll, min(mx, a[i]) - 20);
    ll val = take * i;
    w -= val;
    a[i] -= take;
    sum += a[i] * i;
  }

  if (sum <= w) {
    ll ans = copy_w - (w - sum);
    cout << ans << '\n';
    return 0;
  }

  // cout << w << '\n';
  assert(w < 1000);
  memset(dp, -1, sizeof dp);
  ll ans = copy_w - (w - f(1, w));
  cout << ans << '\n';

  return 0;
}