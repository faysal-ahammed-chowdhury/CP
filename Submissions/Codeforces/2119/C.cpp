#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, l, r, k; cin >> n >> l >> r >> k;
  if (n & 1) {
    cout << l << '\n';
    return;
  }

  int msb = __lg(l);
  int last = (1ll << (msb + 1));

  if (last > r or n == 2) {
    cout << -1 << '\n';
    return;
  }

  if (k == n - 1 or k == n) cout << last << '\n';
  else cout << l << '\n';
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