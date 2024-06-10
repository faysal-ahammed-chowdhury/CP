#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, f, k; cin >> n >> f >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int val = a[f];
  sort(a + 1, a + n + 1);
  // reverse(a + 1, a + n + 1);
  int l = lower_bound(a + 1, a + n + 1, val) - a;
  int r = upper_bound(a + 1, a + n + 1, val) - a - 1;
  l = n - l + 1;
  r = n - r + 1;
  swap(l, r);
  if (r <= k) {
    cout << "YES\n";
  }
  else if (l > k) {
    cout << "NO\n";
  }
  else {
    cout << "MAYBE\n";
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