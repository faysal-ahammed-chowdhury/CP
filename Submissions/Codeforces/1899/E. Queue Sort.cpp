#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int mn = inf;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  int idx = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mn) {
      idx = i;
      break;
    }
  }
  if (!is_sorted(a + idx, a + 1 + n)) {
    cout << -1 << '\n';
    return;
  }
  cout << idx - 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}