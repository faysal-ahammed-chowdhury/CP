#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  bool first = true;
  int i = 1;
  while (i <= n) {
    char starting_char = s[i];
    if (!first and s[i] != 'a') {
      cout << "NO\n";
      return;
    }
    first = false;
    for (char c = starting_char; c <= 'z' and i <= n; c++, i++) {
      if (s[i] != c) {
        cout << "NO\n";
        return;
      }
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