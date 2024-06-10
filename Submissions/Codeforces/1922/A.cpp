#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string a, b, c; cin >> a >> b >> c;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i] and a[i] != c[i]) {
      cout << "YES\n";
      return;
    }
    if (a[i] != b[i] and (c[i] != a[i] and c[i] != b[i])) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}