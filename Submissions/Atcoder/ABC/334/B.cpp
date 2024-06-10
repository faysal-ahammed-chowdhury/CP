#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, m, l, r; cin >> a >> m >> l >> r;
  if (a >= l and r >= a) {
    int ans = 1;
    int d = abs(a - r);
    ans += d / m;
    d = abs(a - l);
    ans += d / m;
    cout << ans << '\n';
  }
  else if (l >= a) {
    int ans = (l == a ? 1 : 0);
    int d = abs(a - r);
    ans += d / m;
    d = abs(a - (l - 1));
    ans -= d / m;
    cout << ans << '\n';
  }
  else {
    int ans = (r == a ? 1 : 0);
    int d = abs(a - l);
    ans += d / m;
    d = abs(a - (r + 1));
    ans -= d / m;
    cout << ans << '\n';
  }

  return 0;
}