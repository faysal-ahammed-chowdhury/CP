#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int tot = n - m;
  for (int i = n, j = 1; j <= tot; j++, i--) {
    cout << i << ' ';
  }
  for (int i = 1; i <= m; i++) {
    cout << i << ' ';
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