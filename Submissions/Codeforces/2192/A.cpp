#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int ans = 0;
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    if (s[i] != s[i - 1]) ans++;
    else flag = true;
  }

  if (s[1] != s[n] and flag) {
    ans++;
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