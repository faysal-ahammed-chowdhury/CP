#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  while (m--) {
    char c; cin >> c;
    int l, r; cin >> l >> r;
    if (c == '+') {
      if (mx >= l and mx <= r) ++mx;
      cout << mx << ' ';
    }
    else {
      if (mx >= l and mx <= r) --mx;
      cout << mx << ' ';
    }
  }
  cout << '\n';
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