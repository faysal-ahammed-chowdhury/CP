#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, s, m; cin >> n >> s >> m;
  int start[n + 1], end[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> start[i] >> end[i];
  }
  for (int i = 1; i < n; i++) {
    int x = end[i];
    int y = start[i + 1];
    if (y - x >= s) {
      cout << "YES\n";
      return;
    }
  }
  if (start[1] >= s or m - end[n] >= s) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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