#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int ans = 0;
  if (s[1] == 'u') ans++;
  if (s[n] == 'u') ans++;
  s[1] = 's', s[n] = 's';

  for (int i = 1; i <= n; i++) {
    if (s[i] == 'u' and s[i - 1] == 'u') {
      ans++;
      s[i] = 's';
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