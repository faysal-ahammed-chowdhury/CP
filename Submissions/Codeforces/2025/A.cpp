#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t; cin >> s >> t;
  int ans = s.size() + t.size();
  int common = 0, mn = min(s.size(), t.size());
  for (int i = 0; i < mn; i++) {
    if (s[i] == t[i]) common++;
    else break;
  }
  int ans2 = ans - common + 1;
  cout << min(ans, ans2) << '\n';
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