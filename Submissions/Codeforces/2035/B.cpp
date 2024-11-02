#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int rem = 0;
  string s = "";
  if (n & 1) {
    for (int i = 1; i <= n - 4; i++) {
      s += '3';
      rem = (((rem * 10) % 66) + 3) % 66;
    }
    s += '6';
    s += '3';
    s += '6';
    s += '6';
    rem = (((rem * 10) % 66) + 6) % 66;
    rem = (((rem * 10) % 66) + 3) % 66;
    rem = (((rem * 10) % 66) + 6) % 66;
    rem = (((rem * 10) % 66) + 6) % 66;
  }
  else {
    for (int i = 1; i <= n - 2; i++) {
      s += '3';
      rem = (((rem * 10) % 66) + 3) % 66;
    }
    s += '6';
    s += '6';
    rem = (((rem * 10) % 66) + 6) % 66;
    rem = (((rem * 10) % 66) + 6) % 66;
  }

  if (rem == 0) cout << s << '\n';
  else cout << -1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}