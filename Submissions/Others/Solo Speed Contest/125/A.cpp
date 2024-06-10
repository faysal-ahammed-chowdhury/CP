#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  int ans = 2;
  if (a == c or a == d) ans--;
  if (b == c or b == d) ans--;
  cout << ans << '\n';
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