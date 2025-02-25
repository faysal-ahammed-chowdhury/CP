#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, p; cin >> n >> k >> p;
  int mx = n * p;

  if (mx < abs(k)) {
    cout << -1 << '\n';
    return;
  }

  k = abs(k);

  cout << ((k + p - 1) / p) << '\n';
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