#include <bits/stdc++.h>
using namespace std;

void solve() {
  char c; int d; cin >> c >> d;
  int n = c - 'a' + 1;
  for (int i = 1; i <= 8; i++) {
    if (i == d) continue;
    cout << c << i << '\n';
  }
  for (char x = 'a'; x <= 'h'; x++) {
    if (x == c) continue;
    cout << x << d << '\n';
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