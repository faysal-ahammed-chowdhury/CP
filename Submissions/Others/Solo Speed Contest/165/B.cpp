#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 1000;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int cnt = 0;
    while (x % 2 == 0) {
      cnt++;
      x /= 2;
    }
    ans = min(ans, cnt);
  }
  cout << ans << '\n';

  return 0;
}