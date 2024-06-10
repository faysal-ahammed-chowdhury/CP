#include <bits/stdc++.h>
using namespace std;

bool ok(int x) {
  cout << x << endl;
  string s; cin >> s;
  return s == ">=";
}

int32_t main() {
  int l = 1, r = 1e6, ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << "! " << ans << endl;

  return 0;
}