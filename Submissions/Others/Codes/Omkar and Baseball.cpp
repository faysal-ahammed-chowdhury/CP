#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ok &= i == x;
    if (i == x) a[i] = 0;
    else a[i] = 1;
  }
  int cnt = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == last) continue;
    if (a[i] == 1) cnt++;
    last = a[i];
  }
  if (ok) cout << 0 << '\n';
  else if (cnt == 1) cout << 1 << '\n';
  else cout << 2 << '\n';
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