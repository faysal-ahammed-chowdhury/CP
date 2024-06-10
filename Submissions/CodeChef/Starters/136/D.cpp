#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9, mod = 1e9 + 7;
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
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int nPr(int n, int r) {
  return 1ll * fact[n] * ifact[n - r] % mod;
}

void solve() {
  int n; cin >> n;
  for (int k = 1; k <= n; k++) {
    int full = (n - k + 1) / k;
    int extra = (n - k + 1) % k;
    int rem = n - full - bool(extra);
    int ans = 1ll * fact[full] * fact[rem] % mod;
    int x = extra ? 1ll * (n / k) * (k - (n % k)) % mod : 1;
    ans = 1ll * ans * x % mod;
    cout << ans << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}