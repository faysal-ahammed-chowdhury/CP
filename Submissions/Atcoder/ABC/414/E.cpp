#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  int ans = 1ll * ((1ll * (n % mod) * ((n + 1) % mod)) % mod) * power(2, mod - 2, mod) % mod;
  // cout << ans << '\n';
  ll l = 1;
  while (l <= n) {
    ll x = n / l;
    ll r = n / x;
    // cout << l << ' ' << r << ' ' << x << '\n';
    ans -= 1ll * x * (r - l + 1) % mod;
    if (ans < 0) ans += mod;
    l = r + 1;
  }

  cout << ans << '\n';

  return 0;
}