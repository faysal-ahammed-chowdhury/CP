#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n; cin >> n;
  int xr = 0;
  bool all_one = true;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    xr ^= x;
    all_one &= x == 1;
  }

  cout << "Case " << ++cs << ": ";
  if (all_one) {
    if (n & 1) cout << "Bob\n";
    else cout << "Alice\n";
    return;
  }

  if (xr == 0) cout << "Bob\n";
  else cout << "Alice\n";
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