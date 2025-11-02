#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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


void solve() {
  int n, k; cin >> n >> k;
  int ans = 0;
  // for (int len = 1; len <= n; len++) {
  //   int p = 1ll * nCr(n - 1, len - 1) * k % mod * power(k - 1, len - 1, mod) % mod;
  //   // cout << len << ' ' << p << '\n';
  //   p = 1ll * p * power(power(k, n, mod), mod - 2, mod) % mod;
  //   ans += 1ll * p * len % mod;
  //   ans %= mod;
  // }
  // cout << ans << '\n';
  ans = (1 - (power(k, mod - 2, mod)));
  if (ans < 0) ans += mod;
  ans = 1ll * ans * (n - 1) % mod;
  ans++;
  ans %= mod;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}