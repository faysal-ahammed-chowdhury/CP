#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    xr ^= abs(a[i] - x) - 1;
  }

  cout << "Case " << ++cs << ": ";
  if (xr == 0) cout << "black wins\n";
  else cout << "white wins\n";
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