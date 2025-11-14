#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

const int N = 1e6 + 9, mod = 1e9 + 7;
int fact[N], ifact[N];
int spf[N];

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

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
  vector<int> v;
  int x = n;
  while (x > 1) {
    int p = spf[x];
    while (x % p == 0) {
      x /= p;
    }
    v.push_back(p);
  }

  vector<int> vec;
  for (int mask = 1; mask < (1 << v.size()); mask++) {
    int y = 1;
    for (int i = 0; i < v.size(); i++) {
      if (CHECK(mask, i)) y = 1ll * y * v[i] % mod;
    }
    vec.push_back(y);
  }

  int ans = 0;
  for (auto x : v) {
    int cur = nCr((n / x) - 1, k);
    for (int mask = 1; mask < (1 << v.size()); mask++) {
      int y = 1ll * vec[mask - 1] * x % mod;
      if ((__builtin_popcount(mask) & 1) and n % y == 0) {
        cur -= nCr((n / y) - 1, k);
        if (cur < 0) cur += mod;
      }
      else if (n % y == 0) {
        cur += nCr((n / y) - 1, k);
        cur %= mod;
      }
    }
    assert(cur >= 0);
    ans = (ans + cur) % mod;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  spf_sieve();

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}