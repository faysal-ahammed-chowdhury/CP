#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  bool got_small = false;
  int x = a[1], idx = -1;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      idx = i;
      if (got_small) {
        cout << -1 << '\n';
        return 0;
      }
      got_small = true;
    }
    if (got_small) {
      if (a[i] > x) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  cout << (idx == -1 ? 0 : n - idx + 1) << '\n';

  return 0;
}