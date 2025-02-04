#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n, m; cin >> n >> m;
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x; cin >> x;
      int d = (n - i) + (m - j);
      if (d & 1) xr ^= x; 
    }
  }

  cout << "Case " << ++cs << ": ";
  if (xr != 0) cout << "win\n";
  else cout << "lose\n";
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