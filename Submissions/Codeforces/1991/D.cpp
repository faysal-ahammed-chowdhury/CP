#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n == 1) cout << "1\n1\n";
  else if (n == 2) cout << "2\n1 2\n";
  else if (n == 3) cout << "2\n1 2 2\n";
  else if (n == 4) cout << "3\n1 2 2 3\n";
  else if (n == 5) cout << "3\n1 2 2 3 3\n";
  else {
    cout << 4 << '\n';
    for (int i = 1; i <= n; i++) {
      int x = (i + 1) % 4;
      cout << (x == 0 ? 4 : x) << ' ';
    }
    cout << '\n';
  }
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