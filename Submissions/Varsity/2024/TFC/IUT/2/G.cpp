#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x; cin >> x;
      if (x) {
        cout << j << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}