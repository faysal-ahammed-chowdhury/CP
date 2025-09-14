#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int x, n; cin >> x >> n;
  if (n & 1) cout << x << '\n';
  else cout << 0 << '\n';
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