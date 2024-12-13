#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
  ll n, k; cin >> n >> k;

  if (k == 1) {
    cout << (n % mod) << '\n';
    return;
  }

  int cnt = 0, a = -1, d = -1;
  int last = 1, sec_last = 1, i = 3;
  while (cnt < 1) {
    int cur = (last + sec_last) % k;
    if (cur == 0 and cnt == 0) {
      a = i;
      d = i;
      cnt++;
    }
    sec_last = last;
    last = cur;
    i++;
  }

  assert(a != -1);

  // cout << a << ' ' << d << '\n';

  int ans = (a + (1ll * ((n - 1) % mod) * d % mod)) % mod;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}