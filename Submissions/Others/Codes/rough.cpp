#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 9, mod = 998244353;
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

  int n, m; cin >> n >> m;

  int ans = 0;
  for (int d = 1; d <= n - 1; d++) {
    int op = d + 1;
    int here = n - d;
    int cur = 1ll * nPr(m, 2) * power(op, m - 2, mod) % mod;
    cur = 1ll * cur * here % mod;
    int x = 1ll * (1ll * d * d % mod) * cur % mod;
    ans += x;
    ans %= mod;
  }
  cout << ans << '\n';

  return 0;
}