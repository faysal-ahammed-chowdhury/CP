#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  int ans = 0;
  if (a > c and b > d) ans++;
  else if (a == c and b > d) ans++;
  else if (a > c and b == d) ans++;
  if (b > c and a > d) ans++;
  else if (b == c and a > d) ans++;
  else if (b > c and a == d) ans++;
  cout << ans + ans << '\n';
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