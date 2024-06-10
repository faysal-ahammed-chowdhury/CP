#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 2];
  a[0] = -1e9, a[n + 1] = -1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    }
  }

  while (q--) {
    int i, x; cin >> i >> x;
    if (a[i] != x) {
      if (a[i] == a[i - 1]) {
        cnt--;
      }
      if (a[i] == a[i + 1]) {
        cnt--;
      }
      a[i] = x;
      if (a[i] == a[i - 1]) {
        cnt++;
      }
      if (a[i] == a[i + 1]) {
        cnt++;
      }
    }
    cout << n - cnt << '\n';
  }
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