#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, m; cin >> n >> m;
  int ans = n;
  for (int b = 2; b <= m; b++) {
    int start = b * (b - 1);
    int d = b * b;
    int baki = n - start;
    if (baki >= 0) {
      int x = (baki / d);
      ans += x + 1;
    }
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