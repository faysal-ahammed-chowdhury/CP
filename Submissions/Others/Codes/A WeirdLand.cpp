#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  int x, y, g; cin >> x >> y >> g;
  int b = 1e9 - g;
  int gc = __gcd(g, b);
  g /= gc;
  b /= gc;
  cout << "Case " << ++cs << ": ";
  cout << b << "/" << g << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}