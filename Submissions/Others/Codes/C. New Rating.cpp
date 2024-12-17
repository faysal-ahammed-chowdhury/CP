#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
int n, a[N], f[N], g[N];

bool ok(int x) {
  g[n + 1] = x;
  for (int i = n; i >= 1; i--) {
    if (a[i] >= g[i + 1]) g[i] = g[i + 1] - 1;
    else g[i] = g[i + 1] + 1;
  }

  int mx = -1e9;
  for (int i = 1; i <= n; i++) {
    if (mx >= g[i + 1]) return true;
    mx = max(mx, f[i]);
  }
  return false;

}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > x) x++;
    else if (a[i] < x) x--;
    f[i] = x;
  }

  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }

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