#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  s = '#' + s, t = '#' + t;
  if (n < 3) {
    cout << 0 << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i + 1 <= n; i++) {
    if (s[i] == 'x') continue;
    if (t[i] == '.' and t[i - 1] == 'x' and t[i + 1] == 'x' and s[i - 1] == '.' and s[i + 1] == '.') {
      ans++;
    }
  }
  for (int i = 1; i + 1 <= n; i++) {
    if (t[i] == 'x') continue;
    if (s[i] == '.' and s[i - 1] == 'x' and s[i + 1] == 'x' and t[i - 1] == '.' and t[i + 1] == '.') {
      ans++;
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