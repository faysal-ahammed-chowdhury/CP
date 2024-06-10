#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;

  int ans = 0;
  for (int len = n / 2; len >= 1; len--) {
    int t = 0;
    for (int i = 1; i + len <= n; i++) {
      if (s[i] == s[i + len] or s[i] == '?' or s[i + len] == '?') {
        t++;
      }
      else {
        t = 0;
      }
      if (t == len) {
        ans = max(ans, 2 * len);
        break;
      }
    }
  } 

  cout << ans << '\n';
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