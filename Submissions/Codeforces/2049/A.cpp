#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all_zero = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_zero &= a[i] == 0;
  }
  if (all_zero) {
    cout << 0 << '\n';
    return;
  }

  int idx1 = -1, idx2 = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      idx1 = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != 0) {
      idx2 = i;
      break;
    }
  }

  bool ok = true;
  for (int i = idx1; i <= idx2; i++) {
    ok &= a[i] != 0;
  }
  if (ok) cout << 1 << '\n';
  else cout << 2 << '\n';
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