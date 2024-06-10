#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;

  int cnt_leading_zeros[n + 1];
  memset(cnt_leading_zeros, 0, sizeof cnt_leading_zeros);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') cnt++;
    else {
      cnt_leading_zeros[i] = cnt;
      cnt = 0;
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      int num = 0;
      for (int len = 1; len <= 20; len++) {
        if (i + len - 1 > n) break;
        num = num * 2 + (s[i + len - 1] - '0');
        int need = num - len;
        if (need <= cnt_leading_zeros[i]) ans++;
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