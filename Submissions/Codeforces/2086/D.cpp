#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9, mod = 998244353;
int n = 26, a[27], dp[27][N], fact[N], ifact[N];
int tot;

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

int f(int i, int need) {
  if (i > n) return need == 0 ? (1ll * fact[tot / 2] * fact[tot - (tot / 2)] % mod) : 0;
  int &ans = dp[i][need];
  if (ans != -1) return ans;
  ans = 1ll * f(i + 1, need) * ifact[a[i]] % mod;
  if (a[i] > 0 and need - a[i] >= 0) ans = (ans + (1ll * f(i + 1, need - a[i]) * ifact[a[i]] % mod)) % mod;
  return ans;
}

void solve() {
  tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= tot; j++) {
      dp[i][j] = -1;
    }
  }
  cout << f(1, tot / 2) << '\n';
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