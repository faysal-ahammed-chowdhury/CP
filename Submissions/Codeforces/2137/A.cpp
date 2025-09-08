#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll k, x; cin >> k >> x;
  for (int i = 1; i <= k; i++) {
    x *= 2;
  }

  cout << x << '\n';
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