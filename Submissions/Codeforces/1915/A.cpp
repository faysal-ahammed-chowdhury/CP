#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if (a == b) cout << c << '\n';
  if (a == c) cout << b << '\n';
  if (b == c) cout << a << '\n';
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