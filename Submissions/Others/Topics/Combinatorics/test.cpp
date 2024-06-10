#include <bits/stdc++.h>
using namespace std;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n, m, cs = 0;
  while (cin >> n >> m and n and m) {
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
    }
    cout << "Case " << ++cs << ":\n";
    while (m--) {
      int r; cin >> r;
      r = min(r, n - r);
    }
  }

  return 0;
}