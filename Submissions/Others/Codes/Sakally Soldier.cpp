#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n;

bool ok(int x) {
  return 1ll * x * x + x <= 2 * n;
}

void solve() {
  cin >> n;
  int l = 1, r = 1e8, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  cout << n - ans << '\n';
}

int32_t main() {
  // freopen("alimagde.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}