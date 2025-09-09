#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int inf = 1e18;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) ans += a[i];
    else ans -= a[i];
  }

  int mn = inf;
  int add = (n % 2 == 0 ? a[1] == a[n] ? n - 1 : n - 2 : n - 1);
  for (int i = 2; i <= n; i += 2) {
    mn = min(mn, a[i - 1] + a[i - 1] + (i - 1));
    int cur = a[i] + a[i] + i;
    // cout << cur << ' ' << cur - mn << '\n';
    add = max(add, cur - mn);
  }

  mn = inf;
  for (int i = (n % 2 == 0 ? n - 2 : n - 1); i >= 2; i -= 2) {
    mn = min(mn, a[i + 1] + a[i + 1] - (i + 1));
    int cur = a[i] + a[i] - i;
    // cout << cur << ' ' << cur - mn << '\n';
    add = max(add, cur - mn);
  }

  ans += add;
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