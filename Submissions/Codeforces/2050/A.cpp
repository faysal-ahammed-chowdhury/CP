#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  int tot = 0, ans = 0;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    if (ok and tot + s.size() <= m) {
      tot += s.size();
      ans = i;
    }
    else ok = false;
  }

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