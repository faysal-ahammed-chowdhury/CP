#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 998244353, inf = 1e9;
array<int, 4> a[N];
int pref[N], nxt[N], dp[N];
int n, m;

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

int f(int i) {
  if (i > n) return 1;
  int &ans = dp[i];
  if (~ans) return ans;
  ans = 0;
  if (i + 1 <= n and a[i][0] == a[i + 1][0]) {
    ans += 1ll * (1ll * (a[i][3] - a[i][2]) * power(a[i][3], mod - 2, mod) % mod) * f(i + 1) % mod;
    ans %= mod;
  }
  if (a[i][1] == m) {
    int tmp = 1ll * pref[n] * power(pref[i], mod - 2, mod) % mod;
    ans += 1ll * a[i][2] * power(a[i][3], mod - 2, mod) % mod * tmp % mod;
    ans %= mod;
    return ans;
  }
  if (nxt[i] != -1) {
    int idx = nxt[i];
    int tmp1 = 1ll * a[i][2] * power(a[i][3], mod - 2, mod) % mod;
    int tmp2 = 1ll * pref[idx - 1] * power(pref[i], mod - 2, mod) % mod;
    ans += 1ll * (tmp1) * (tmp2) % mod * f(idx) % mod;
    ans %= mod;
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
  }
  sort(a + 1, a + n + 1);

  for (int i = n; i >= 1; i--) {
    nxt[i] = -1;
    array<int, 4> x = {a[i][1] + 1, -inf, -inf, inf};
    auto it = upper_bound(a + 1, a + n + 1, x);
    if (it != (a + n + 1) and a[i][1] + 1 == (*it)[0]) {
      auto idx = it - a;
      nxt[i] = idx;
    }
  }

  pref[0] = 1;
  for (int i = 1; i <= n; i++) {
    pref[i] = 1ll * pref[i - 1] * (1ll * (a[i][3] - a[i][2])  * power(a[i][3], mod - 2, mod) % mod) % mod;
  }

  memset(dp, -1, sizeof dp);
  cout << f(1) << '\n';

  return 0;
}