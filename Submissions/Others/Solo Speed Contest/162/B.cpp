#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  a[1] = 0;
  a[2] = 0;
  for (int i = 3; i <= n; i++) {
    int last = a[i - 1], idx = -1;
    for (int j = 1; j < i - 1; j++) {
      if (a[j] == last) {
        idx = j;
      }
    }
    if (idx == -1) a[i] = 0;
    else a[i] = (i - 1) - idx;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += a[i] == a[n];
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