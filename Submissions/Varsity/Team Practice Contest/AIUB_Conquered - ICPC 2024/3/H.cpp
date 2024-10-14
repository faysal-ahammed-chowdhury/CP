#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 1, mod = 1e9 + 7;
int fact[N], ifact[N];

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

int nCr(int n, int r) {
  if (r > n) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int nPr(int n, int r) {
  if (r > n) return 0;
  return 1ll * fact[n] * ifact[n - r] % mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
  int xx = n * m - 2;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int z = (i >= 2 ? ((i  - 2) * m) : 0);
      z %= mod;
      a[i][j] = a[i - 1][j] + z;
      a[i][j] %= mod;
      int x = j, y = m - j + 1;
      if (i != 1) {
        z = (x * (x + 1)) / 2;
        z %= mod;
        a[i][j] += z;
        a[i][j] %= mod;
        z = (y * (y + 1)) / 2;
        z %= mod;
        a[i][j] += z;
        a[i][j] %= mod;
        a[i][j] -= 1;
        if (a[i][j] < 0) a[i][j] += mod;
      }
      x = j - 1;
      z = (x * (x + 1)) / 2;
      z %= mod;
      int val = a[i][j] + z;
      val %= mod;
      ans += val * nCr(xx, k - 2) % mod;
      ans %= mod;
    }
  }
  cout << ans << '\n';

  return 0;
}