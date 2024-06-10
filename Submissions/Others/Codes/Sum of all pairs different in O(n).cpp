#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll a[n + 1]; ;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = (pref[i - 1] + (a[i] % mod)) % mod;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int sum = (pref[n] - pref[i]) % mod;
    if (sum < 0) sum += mod;
    int less = (1ll * (a[i] % mod) * (n - i)) % mod;
    ans = (ans + sum) % mod;
    ans = (ans - less) % mod;
    if (ans < 0) ans += mod;
  }

  cout << ans << '\n';

  return 0;
}