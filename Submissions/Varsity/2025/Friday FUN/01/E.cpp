#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

ll r, a, b, mod;
i128 sum(ll a, ll p, ll n) {
  ll x = (a + p);
  i128 ans = ((((i128) x * n) / 2) % mod);
  return (ans) % mod;
}

bool overflow;
ll lcm(ll a, ll b) {
  i128 ans = ((i128)a * b) / __gcd(a, b);
  if (ans > r) overflow = true;
  return overflow ? 0 : (ll)ans;
}

void solve() {
  cin >> r >> a >> b >> mod;

  overflow = false;
  ll c = lcm(a, b);

  ll cnt1 = r / a;
  ll cnt2 = r / b;

  ll ans = (sum(a, (cnt1 * a), cnt1)) % mod;
  ans += sum(b, cnt2 * b, cnt2) % mod;
  ans %= mod;

  if (!overflow) {
    ll cnt3 = r / c;
    ans -= sum(c, cnt3 * c, cnt3) % mod;
    ans %= mod;
    ans += mod;
    ans %= mod;
  }

  cout << ans << '\n';
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