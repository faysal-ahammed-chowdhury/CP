#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 998244353;
int a[N], pref[N];

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

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    int x = 1ll * a[i] * power(2, i - 2, mod) % mod;
    pref[i] = (pref[i - 1] + x) % mod;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = pref[n] - pref[i];
    if (x < 0) x += mod;
    x = 1ll * x * power(power(2, i - 1, mod), mod - 2, mod) % mod;
    ans = (ans + (1ll * a[i] * x % mod)) % mod;
    ans = (ans + (1ll * a[i] * a[i] % mod)) % mod;
  }
  cout << ans << '\n';

  return 0;
}