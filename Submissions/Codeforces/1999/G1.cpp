#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l = 2, r = 999, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    cout << "? " << mid << ' ' << r << endl;
    int x; cin >> x;
    if (x == (mid + 1) * (r + 1)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  // assert(ans != -1);
  cout << "! " << ans << endl;
}

int32_t main() {
  cout.flush();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
