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

int get(int a, int r, int n) {
  int x = (((1 - power(r, n, mod)) % mod) + mod) % mod;
  int y = (((1 - r) % mod) + mod) % mod;
  int ans = 1ll * a * x % mod;
  ans = 1ll * ans * power(y, mod - 2, mod) % mod;
  return ans;
}

void solve() {
  int i1, i2, j1, j2; cin >> i1 >> i2 >> j1 >> j2;

  int x = get(1, 3, j2 + 1);
  if (j1 != 0) {
    int y = get(1, 3, j1);
    x = (((x - y) % mod) + mod) % mod;
  }

  int z = get(1, 2, i2 + 1);
  if (i1 != 0) {
    int y = get(1, 2, i1);
    z = (((z - y) % mod) + mod) % mod;
  }

  int ans = 1ll * x * z % mod;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}