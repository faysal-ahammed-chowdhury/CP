#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l = 1, r = 999;
  while (r - l > 2) {
    int mid1 = (2 * l + r) / 3, mid2 =  (2 * r + l) / 3;
    cout << "? " << mid1 << ' ' << mid2 << endl;
    int x; cin >> x;
    if (x == (mid1 * mid2)) {
      l = mid2;
    }
    else if (x == ((mid1 + 1) * (mid2 + 1))) {
      r = mid1;
    }
    else {
      l = mid1;
      r = mid2;
    }
  }
  if (r - l == 2) {
    cout << "? 1 " << l + 1 << endl;
    int x; cin >> x;
    if (x == l + 1) l = l + 1;
    else r = l + 1;
  }
  cout << "! " << r << endl;
}

int32_t main() {
  cout.flush();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
