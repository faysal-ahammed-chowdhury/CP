#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  if (s.size() < 3) {
    cout << "NO\n";
    return;
  }
  if (s[0] == '1' and s[1] == '0') {
    string t = s.substr(2);
    if (t[0] == '0') cout << "NO\n";
    else {
      int n = stoi(t);
      if (n >= 2) cout << "YES\n";
      else cout << "NO\n";
    }
  }
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