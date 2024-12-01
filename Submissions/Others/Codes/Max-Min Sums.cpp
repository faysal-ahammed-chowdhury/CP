#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;
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
  prec(); // must include

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }

  sort(a + 1, a + n + 1);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = i - 1;
    int r = n - i;
    ans += 1ll * nCr(l, k - 1) * a[i] % mod;
    ans %= mod;
    ans -= 1ll * nCr(r, k - 1) * a[i] % mod;
    if (ans < 0) ans += mod;
  }
  cout << ans << '\n';

  return 0;
}