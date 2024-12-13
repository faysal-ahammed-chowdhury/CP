#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
int n, a[N];

bool ok(int i, int x) {
  return (a[i] + a[i + 1] <= x);
}

int calc(int x) {
  int ans = &a[n] - upper_bound(a + 1, a + n + 1, x) + 1;
  int l = 1, r = n - 1, idx = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid, x)) {
      idx = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  ans += idx;
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int ans = inf;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, calc(a[i]));
  }
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