#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int a, b, x, y; cin >> a >> b >> x >> y;
  if (a - 1 == b and a % 2 == 1) {
    cout << y << '\n';
    return;
  }
  if (a > b) {
    cout << -1 << '\n';
    return;
  }

  if (a == b) {
    cout << 0 << '\n';
    return;
  }

  int ans = 0;
  while (a < b) {
    if (a % 2 == 0) {
      ans += min(x, y);
    }
    else ans += x;
    a++;
  }

  cout << ans << '\n';
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