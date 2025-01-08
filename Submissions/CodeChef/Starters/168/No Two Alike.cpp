#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1], st[n + 1], en[n + 1];
  memset(st, -1, sizeof st);
  memset(en, -1, sizeof en);
  int uniq = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (st[a[i]] == -1) {
      st[a[i]] = i;
      uniq++;
    }
    en[a[i]] = i;
  }

  int ans = uniq, mx = 0;;
  for (int i = 1; i <= n; i++) {
    if (st[a[i]] == en[a[i]]) {
      if (mx < st[a[i]]) ans--;
    }
    mx = max(mx, en[a[i]]);
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