#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
map<int, int> mp;

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

int f(int n, int k) {
  return power(mp[k], n, mod);
}

void solve() {
  int l, r, k; cin >> l >> r >> k;
  if (k >= 10) {
    cout << 0 << '\n';
    return;
  }
  int x = f(r, k) - 1;
  if (x < 0) x += mod;
  int y = f(l, k) - 1;
  if (y < 0) y += mod;
  int ans = x - y;
  if (ans < 0) ans += mod;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp[1] = 10;
  mp[2] = 5;
  mp[3] = 4;
  mp[4] = 3;
  mp[5] = 2;
  mp[6] = 2;
  mp[7] = 2;
  mp[8] = 2;
  mp[9] = 2;

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}