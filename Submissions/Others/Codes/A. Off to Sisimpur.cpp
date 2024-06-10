#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int i = 0, j = n - 1;
  bool ok = true;
  while (i < j) {
    int d = abs(s[i++] - s[j--]);
    ok &= (d == 2) or (d == 0);
  }
  if (ok) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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