#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x >= k) {
      sum += x;
    }
    if (x == 0 and sum > 0) {
      ans++;
      sum--;
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