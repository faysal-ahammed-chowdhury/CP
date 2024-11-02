#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 1e9 + 7;
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
  string a, b; cin >> a >> b;
  int match = 0;
  for (int i = 0; i < n; i++) {
    match += a[i] == b[i];
  }
  int mismatch = n - match;
  if (mismatch & 1) cout << 0 << '\n';
  else {
    int x = mismatch / 2;
    int ans = nCr(mismatch, x);
    ans = 1ll * ans * power(2, match, mod) % mod;
    cout << ans << '\n';
  }
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