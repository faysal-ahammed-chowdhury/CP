#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int ans = 0;
  for (int d = 1; d <= n; d++) {
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'A' and i + d <= n and s[i + d] == 'B' and i + d + d <= n and s[i + d + d] == 'C') {
        ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}