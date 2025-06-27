#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e7;

bool ok(int a, int mn, int mx) {
  if (mn <= a and mx >= a) return true;
  if (mn <= a + 1 and mx >= a + 1) return true;
  if (mn <= a - 1 and mx >= a - 1) return true;
  return false;
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1 and abs(a[i] - a[i - 1]) <= 1) ans = 0;
  }

  if (ans == 0) {
    cout << 0 << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    int mn = inf, mx = -inf;
    for (int j = i + 1; j <= n; j++) {
      mn = min(mn, a[j]);
      mx = max(mx, a[j]);

      if (ok(a[i], mn, mx)) {
        ans = min(ans, (j - i - 1));
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int mn = inf, mx = -inf;
    for (int j = i - 1; j >= 1; j--) {
      mn = min(mn, a[j]);
      mx = max(mx, a[j]);

      if (ok(a[i], mn, mx)) {
        ans = min(ans, (i - j - 1));
      }
    }
  }

  if (ans == inf) ans = -1;
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