#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int ans = 0;
  if (x1 >= 0 and x2 <= 0) {
    ans++;
  }
  if (x1 <= 0 and x2 >= 0) {
    ans++;
  }

  if (y1 >= 0 and y2 <= 0) {
    ans++;
  }

  if (y1 <= 0 and y2 >= 0) {
    ans++;
  }

  ans = min(ans, 1);

  cout << ans << '\n';

  return 0;
}