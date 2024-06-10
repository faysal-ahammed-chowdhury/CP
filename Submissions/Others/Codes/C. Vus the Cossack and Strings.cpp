#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  s = '.' + s, t = '.' + t;
  int pref[n + 1];
  pref[0] = 1;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == '1');
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    cnt += t[i] == '1';
  }

  int ans = 0;
  for (int i = 1; i + m - 1 <= n; i++) {
    int x = cnt + (pref[i + m - 1] - pref[i - 1]);
    ans += x % 2 == 0;
  }
  cout << ans << '\n';

  return 0;
}