#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  long long ans = 0;
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n / a; b++) {
      int c = (n - (a * b)) / (a + b);
      c = min(c, x - a - b);
      ans += max(c, 0);
    }
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