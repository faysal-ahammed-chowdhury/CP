#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1' and s[i] != s[i - 1]) cnt++;
  }

  int ans = cnt * 2;
  if (s[n] == '1') ans--;

  cout << ans << '\n';
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