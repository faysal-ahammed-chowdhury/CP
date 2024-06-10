#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int mx1 = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mx1 = max(mx1, x);
  }
  int m; cin >> m;
  int mx2 = 0;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    mx2 = max(mx2, x);
  }

  cout << mx1 << ' ' << mx2 << '\n';

  return 0;
}