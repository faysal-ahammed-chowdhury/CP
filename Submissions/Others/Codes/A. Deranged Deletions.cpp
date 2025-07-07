#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int mx = 0, another = -1;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x < mx) another = x;
    if (another == -1) mx = max(mx, x);
  }

  if (another == -1) cout << "No\n";
  else {
    cout << "YES\n";
    cout << 2 << '\n';
    cout << mx << ' ' << another << '\n';
  }
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