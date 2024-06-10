#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int ans = n;
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 2; b++) {
      for (int c = 0; c < 5; c++) {
        for (int d = 0; d < 3; d++) {
          long long x = (a * 1) + (b * 3) + (c * 6) + (d * 10);
          if ((n - x) >= 0 and (n - x) % 15 == 0) {
            ans = min(1ll * ans, (a + b + c + d + ((n - x) / 15)));
          }
        }
      }
    }
  }
  cout << ans << '\n';
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