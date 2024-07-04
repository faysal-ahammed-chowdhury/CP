#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long sum = 0, xr = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x, xr ^= x;
  }
  cout << 2 << '\n';
  cout << xr << ' ' << sum + xr << '\n';
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