#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool ok = true;
  for (int i = 2; i <= n; i++) {
    ok &= (abs((a[i] - a[i - 1])) == 5 or abs(a[i] - a[i - 1]) == 7);
  }
  if (ok) cout << "YES\n";
  else cout << "NO\n";
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