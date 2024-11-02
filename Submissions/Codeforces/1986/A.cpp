#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  int mn = min({a, b, c});
  int mx = max({a, b, c});
  cout << mx - mn << '\n';
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