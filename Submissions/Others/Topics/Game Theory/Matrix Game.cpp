#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n, m; cin >> n >> m;
  long long xr = 0;
  for (int i = 1; i <= n; i++) {
    long long sum = 0;
    for (int j = 1; j <= m; j++) {
      int x; cin >> x;
      sum += x;
    }
    xr ^= sum;
  }

  cout << "Case " << ++cs << ": ";
  if (xr == 0) cout << "Bob\n";
  else cout << "Alice\n";
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