#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  if (s[0] != '1' or s[n - 1] == '9') {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == '0') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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