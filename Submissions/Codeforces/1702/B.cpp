#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  set<char> se;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (se.size() == 3 and se.find(s[i]) == se.end()) {
      ans++;
      se.clear();
    }
    se.insert(s[i]);
  }
  cout << ++ans << '\n';
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