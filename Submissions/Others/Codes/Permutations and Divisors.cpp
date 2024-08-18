#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int f(int n) {
  int len = 0, ans = 0;
  for (int k = 1; k <= 30; k++) {
    int here = (1ll << k) - (1ll << (k - 1));
    if (len + here > n) {
      here = n - len;
    }
    if (here == 0) break;
    ans = (ans + (here * k % mod)) % mod;
    len += here;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    int ans = f(r) - f(l - 1);
    if (ans < 0) ans += mod;
    cout << ans << '\n';
  }

  return 0;
}