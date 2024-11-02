#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, p; cin >> n >> p;
  int tot = n + n + p;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (tot > 0) {
        cout << i << ' ' << j << '\n';
        tot--;
      }
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