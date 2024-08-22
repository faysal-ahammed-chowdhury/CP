#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int m; cin >> m;
  while (m--) {
    string s; cin >> s;
    int x = s.size();
    if (x != n) {
      cout << "NO\n";
      continue;
    }
    s = '.' + s;
    map<int, char> mp1;
    map<char, int> mp2;
    bool ok = true;
    for (int i = 1; i <= x; i++) {
      if (mp1.find(a[i]) == mp1.end()) mp1[a[i]] = s[i];
      else if (mp1[a[i]] != s[i]) ok = false;
      if (mp2.find(s[i]) == mp2.end()) mp2[s[i]] = a[i];
      else if (mp2[s[i]] != a[i]) ok = false;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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