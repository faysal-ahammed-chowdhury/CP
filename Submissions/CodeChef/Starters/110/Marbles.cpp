#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b; cin >> a >> b;
  for (int i = 0; i <= 1000; i++) {
    if ((b - i) > 0 and ((a + i) % (b - i)) == 0) {
      cout << i << '\n';
      return;
    }
    if ((a - i) > 0 and ((a - i) % (b + i)) == 0) {
      cout << i << '\n';
      return;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}