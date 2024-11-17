#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  int idx = -1, zero, val;
  for (int i = 2; i <= n; i++) {
    cout << "? " << 1 << ' ' << i << endl;
    int cnt; cin >> cnt;
    if (cnt > 0) {
      idx = i;
      zero = cnt;
      val = cnt;
      break;
    }
  }

  if (idx == -1) {
    cout << "! IMPOSSIBLE" << endl;
    return;
  }

  int leading_one = idx - zero - 1;
  string s = "";
  for (int i = 1; i <= leading_one; i++) {
    s += '1';
  }
  for (int i = 1; i <= zero; i++) {
    s += '0';
  }
  s += '1';
  // cout << idx << ' ' << s << '\n';

  for (int i = idx + 1; i <= n; i++) {
    cout << "? " << leading_one + 1 << ' ' << i << endl;
    int cnt; cin >> cnt;
    if (cnt == val) {
      s += '0';
      zero++;
    }
    else if (cnt == val + zero) {
      s += '1';
    }
    else {
      cout << "! IMPOSSIBLE" << endl;
      return;
    }
    val = cnt;
  }

  cout << "! " << s << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}