#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  s = '.' + s;
  t = '.' + t;
  int must = 0, optional = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1' and t[i] == '1') must++;
    else if (s[i] == '1' or t[i] == '1') optional++;
  }

  if (must & 1) cout << "YES\n";
  else if (optional > 0) cout << "YES\n";
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