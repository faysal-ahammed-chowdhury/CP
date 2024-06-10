#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  char a, b; cin >> a >> b;
  int d = abs(a - b);
  cout << "Case " << ++cs << ": \n";
  for (int i = 1; i <= d; i++) {
    if (d % i == 0) {
      int x = (94 + i - 1) / i;
      cout << i << ' ' << x << '\n';
    }
  }
  cout << '\n';
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