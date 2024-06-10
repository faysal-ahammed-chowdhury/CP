#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9, mod = 1e9 + 7;
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

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(int x) const { return x ^ RANDOM; }
};

void solve() {
  int x, y; cin >> x >> y;
  unordered_map<int, int, chash> pf;
  for (int i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      pf[i]++;
      x /= i;
    }
  }
  if (x > 1) pf[x]++;
  int ans = 1;
  for (auto [p, pw] : pf) {
    ans = 1ll * ans * nCr(pw + y - 1, pw) % mod;
  }
  ans = 1ll * ans * power(2, y - 1, mod) % mod;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}