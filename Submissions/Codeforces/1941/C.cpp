#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i + 4 <= n) {
      if (s[i] == 'm' and s[i + 1] == 'a' and s[i + 2] == 'p' and s[i + 3] == 'i' and s[i + 4] == 'e') {
        ans++;
        i += 3;
      }
      else if (s[i] == 'm' and s[i + 1] == 'a' and s[i + 2] == 'p') {
        ans++;
      }
      else if (s[i] == 'p' and s[i + 1] == 'i' and s[i + 2] == 'e') {
        ans++;
      }
    }
    else if (i + 2 <= n) {
      if (s[i] == 'm' and s[i + 1] == 'a' and s[i + 2] == 'p') {
        ans++;
      }
      else if (s[i] == 'p' and s[i + 1] == 'i' and s[i + 2] == 'e') {
        ans++;
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