#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int x; cin >> x;
  return x;
}

int32_t main() {
  int n; cin >> n;

  int l = 1, r = n, ans = -1;

  while (r - l >= 1) {
    int idx = query(l, r);
    ans = idx;

    if (r - l == 1) break;
    int mid = (l + r) >> 1;
    if (idx <= mid) {
      if (mid - l < 1) break;
      int idx2 = query(l, mid);
      if (idx == idx2) r = mid;
      else l = mid;
    }
    else {
      if (r - (mid) < 1) break;
      int idx2 = query(mid, r);
      if (idx == idx2) l = mid;
      else r = mid;
    }
  }

  cout << "! " << (l != ans ? l : r) << endl;

  return 0;
}