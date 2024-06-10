#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y; cin >> x >> y;
  int rem = 100 - y;
  if (rem == 0) {
    cout << -1 << '\n';
    return;
  }
  int cost = ((x * 100) + rem - 1) / rem;
  cout << cost << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}