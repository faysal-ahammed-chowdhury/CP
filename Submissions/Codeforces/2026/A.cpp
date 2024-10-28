#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y, k; cin >> x >> y >> k;
  int mn = min(x, y);
  cout << "0 0 " << mn << ' ' << mn << '\n';
  cout << "0 " << mn << ' ' << mn << " 0" << '\n';
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