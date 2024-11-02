#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s[n + 1];
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    ok |= s[i].size() == 1;
    if (s[i].size() > 1) ok |= (s[i][0] == s[i].back() and s[i][0] == s[i][1]);
    if (s[i].size() > 2) ok |= s[i][0] == s[i][2];
  }
  if (ok) {
    cout << "YES\n";
    return;
  }
  set<string> se, se2;
  for (int i = 1; i <= n; i++) {
    if (se.find(s[i]) != se.end()) {
      cout << "YES\n";
      return;
    }
    if (s[i].size() == 2 and se2.find(s[i]) != se2.end()) {
      cout << "YES\n";
      return;
    }
    string t = s[i].substr(1);
    if (t.size() == 2 and se.find(t) != se.end()) {
      cout << "YES\n";
      return;
    }
    t = s[i];
    reverse(t.begin(), t.end());
    se.insert(t);
    t = s[i];
    reverse(t.begin(), t.end());
    t = t.substr(1);
    if (t.size() == 2) se2.insert(t);
  }
  cout << "NO\n";
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