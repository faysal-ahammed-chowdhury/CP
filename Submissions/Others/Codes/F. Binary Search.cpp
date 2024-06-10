#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1005, mod = 1e9 + 7;
int cnt_less, cnt_big;

void get(int n, int pos) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (mid <= pos) {
      if (pos != mid) cnt_less++;
      l = mid + 1;
    }
    else {
      cnt_big++;
      r = mid;
    }
  }
}

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int n, x, pos; cin >> n >> x >> pos;
  get(n, pos);
  int other = n - cnt_less - cnt_big - 1;
  int ans = fact[other];

  int y = 1ll * nCr(x - 1, cnt_less) * fact[cnt_less] % mod;
  ans = 1ll * ans * y % mod;
  int z = 1ll * nCr(n - x, cnt_big) * fact[cnt_big] % mod;
  ans = 1ll * ans * z % mod;

  cout << ans << '\n';

  return 0;
}