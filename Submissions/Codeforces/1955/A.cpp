#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b; cin >> n >> a >> b;
  double x = b / 2.0;
  int ans = 0;
  if (x <= a) {
    int half = n / 2;
    ans = half * b;
    if (n & 1) ans += a;
  }
  else {
    ans = n * a;
  }
  cout << ans << '\n';
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