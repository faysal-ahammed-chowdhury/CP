#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll k, ll l, ll r) {
  ll mn = (1ll << k);
  ll mx = (mn * 2) - 1;
  mn = max(mn, l);
  mx = min(mx, r);
  if (mn > mx) return 0;
  return mx - mn + 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, l, r; cin >> n >> l >> r;
  ll ans = 0;
  for (int k = 0; k < 60; k++) {
    if ((1ll << k) & n) {
      ans += f(k, l, r);
    }
  }
  cout << ans << '\n';
  
  return 0;
}