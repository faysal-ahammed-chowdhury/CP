#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int d[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i < 10 or (i % 11 == 0)) {
      int x = i % 10;
      while (x <= d[i]) {
        ans++;
        x *= 10;
        x += (i % 10);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}