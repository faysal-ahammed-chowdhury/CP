#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;

  if (k % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      if (i == n - 1) {
        cout << n << ' ';
      }
      else cout << n - 1 << ' ';
    }
    cout << '\n';
  }
  else {
    for (int i = 1; i <= n; i++) {
      if (i == n) {
        cout << n - 1 << ' ';
      }
      else cout << n << ' ';
    }
    cout << '\n';
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