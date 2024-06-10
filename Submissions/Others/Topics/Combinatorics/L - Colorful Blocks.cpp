#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 998244353;
int fact[N], ifact[N];

int power(int b, int p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int n, m, k; cin >> n >> m >> k;

  int ans = 0;
  for (int i = 0; i <= k; i++) {
    ans += 1ll * nCr(n - 1, i) * m % mod * power(m - 1, n - i - 1, mod) % mod;
    ans %= mod;
  } 

  cout << ans << '\n';

  return 0;
}