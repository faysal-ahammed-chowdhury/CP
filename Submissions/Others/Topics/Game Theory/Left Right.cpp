#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n; cin >> n;
  int a[n + n + 1];
  for (int i = 1; i <= n + n; i++) {
    cin >> a[i];
  }

  int xr = 0;
  for (int i = 1; i <= n + n; i += 2) {
    xr ^= abs(a[i] - a[i + 1]) - 1;
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