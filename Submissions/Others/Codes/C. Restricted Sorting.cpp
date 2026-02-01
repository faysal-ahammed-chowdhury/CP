#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 1e18;
int n, a[N], b[N];

int f(int x, int y) {
  int here = abs(x - y);
  int m = b[1];
  here = max(here, min(abs(m - x), abs(m - y)));
  m = b[n];
  here = max(here, min(abs(m - x), abs(m - y)));
  auto it = lower_bound(b + 1, b + n + 1, (x + y) / 2);
  m = *it;
  here = max(here, min(abs(m - x), abs(m - y)));
  --it;
  if (it != b) {
    m = *it;
    here = max(here, min(abs(m - x), abs(m - y)));
  }
  return here;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);

  int ans = inf;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) continue;
    int here = f(a[i], b[i]);
    here = max(here, min(f(a[i], b[1]), f(b[i], b[1])));
    here = max(here, min(f(a[i], b[n]), f(b[i], b[n])));
    ans = min(ans, here);
    // cout << a[i] << ' ' << b[i] << ' ' << here << '\n';
  }
  if (ans >= inf) ans = -1;
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