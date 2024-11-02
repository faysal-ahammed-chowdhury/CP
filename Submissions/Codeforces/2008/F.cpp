#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

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

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int psum[n + 1];
  psum[0] = 0;
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + a[i];
  }
  int p = 0;
  for (int i = 1; i <= n; i++) {
    int x = psum[n] - psum[i];
    x %= mod;
    p += 1ll * a[i] * x % mod;
    p %= mod;
  }
  int q = 1ll * ((1ll * n * (n - 1)) / 2) % mod;
  int ans = 1ll * p * power(q, mod - 2, mod) % mod;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}