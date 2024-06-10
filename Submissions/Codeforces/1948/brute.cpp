#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int len = j - i + 1;
      if (len & 1) continue;
      
      int half = len / 2;
      bool ok = true;
      for (int k = i; k < i + half; k++) {
        if (s[k] == '?' or s[k + half] == '?') continue;
        else if (s[k] != s[k + half]) {
          ok = false;
          break;
        }
      }
      if (ok) ans = max(ans, len);

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