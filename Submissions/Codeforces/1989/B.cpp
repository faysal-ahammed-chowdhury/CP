#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  a = '.' + a;
  b = '.' + b;
  int mx = 0;
  for (int i = 1; i <= m; i++) {
    int now = i;
    for (int j = 1; j <= n and now <= m; j++) {
      if (a[j] == b[now]) {
        now++;
      }
    }
    int d = now - i;
    mx = max(mx, d);
  }
  int ans = n + m - mx;
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