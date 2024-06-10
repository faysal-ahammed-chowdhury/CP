#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll get_sum(int n) {
  return (1ll * n * (n + 1)) / 2;
}

int f(int n) {
  int ans = 0, cnt = 1, l = 1, r = 9;
  while (l <= n) {
    r = min(r, n);
    int sum = ((get_sum(r) % mod) - (get_sum(l - 1) % mod)) % mod;
    if (sum < 0) sum += mod;
    ans = (ans + (1ll * sum * cnt % mod)) % mod;
    cnt++, l *= 10, r = r * 10 + 9;
  }
  return ans;
}

void solve() {
  int l, r; cin >> l >> r;
  int ans = (f(r) - f(l - 1)) % mod;
  if (ans < 0) ans += mod;
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