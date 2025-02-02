#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == k) {
    for (int i = 2, j = 1; i <= n; i += 2, j++) {
      if (a[i] != j) {
        cout << j << '\n';
        return;
      }
    } 

    cout << (n / 2) + 1 << '\n';
    return;
  }

  for (int i = 2; i <= n; i++) {
    if (a[i] != 1 and (n - i) >= k - 2) {
      cout << 1 << '\n';
      return;
    }
  }

  cout << 2 << '\n';
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