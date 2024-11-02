#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9, inf = 1e18;
int n, k, tot, mx, a[N];

bool ok(int sz) {
  int possible = tot / sz;
  int rem = tot - (sz * possible);
  if ((rem % sz != 0) and ((rem + k) / sz) == (rem / sz)) return 0;
  rem += k;
  possible += rem / sz;
  // cout << possible << '\n';
  return possible >= mx;
}

void solve() {
  cin >> n >> k;
  tot = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
    mx = max(mx, a[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (ok(i)) {
      cout << i << '\n';
      break;
    }
  }
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