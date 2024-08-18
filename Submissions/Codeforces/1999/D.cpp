#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  int j = 0;
  for (int i = 0; i < n and j < m; i++) {
    if (s[i] == '?') {
      s[i] = t[j];
      j++;
    }
    else if (s[i] == t[j]) j++;
  }
  if (j == m) {
    cout << "YES\n";
    for (auto &c : s) if (c == '?') c = 'a';
    cout << s << '\n';
  }
  else cout << "NO\n";
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