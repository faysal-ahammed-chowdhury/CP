#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 998244353; 
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
  int n; cin >> n;
  int a[n + 1];
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt += a[i];
  }

  if (cnt != n) {
    cout << 0 << '\n';
    return;
  }
  
  int half = (n + 1) / 2;
  cnt = 0;
  for (int i = half; i >= 1; i--) {
    cnt += a[i];
  }

  if (cnt != n) {
    cout << 0 << '\n';
    return;
  }

  int ans = 1, rem = 0;
  for (int i = half; i >= 1; i--) {
    int x = 2;
    if (i == half and (n & 1)) x = 1;
    int cap = a[i];

    rem += x;

    if (cap > rem) {
      cout << 0 << '\n';
      return;
    }

    int cur_way = nCr(rem, cap);
    ans = 1ll * ans * cur_way % mod;
    rem -= cap;
  }

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