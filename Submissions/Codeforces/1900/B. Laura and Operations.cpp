#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  int d = abs(b - c);
  if (d % 2 == 0) {
    cout << 1 << ' ';
  }
  else cout << 0 << ' ';

  d = abs(a - c);
  if (d % 2 == 0) {
    cout << 1 << ' ';
  }
  else cout << 0 << ' ';

  d = abs(a - b);
  if (d % 2 == 0) {
    cout << 1 << ' ';
  }
  else cout << 0 << ' ';
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