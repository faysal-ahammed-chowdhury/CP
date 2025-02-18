#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  n -= 2;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int last = -1, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) cnt++;
    else {
      if (last == -1) {
        cnt = 0;
        last = i;
        continue;
      }
      last = i;
      if (cnt == 0) continue;

      if (cnt < 2) {
        cout << "NO\n";
        return;
      }
      cnt = 0;
    }
  }

  cout << "YES\n";
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