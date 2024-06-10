#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  ll ans = inf;
  for (int b = 0; b <= 60; b++) {
    ll x = (1ll << b);
    if (x > n) break;
    ll a = (n / x);
    ll val = a * x;
    ll c = n - val;
    ans = min(ans, a + b + c);
  }

  cout << ans << '\n';

  return 0;
}