#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = n - 1;
  for (int i = 1; i <= n; i++) {
    int cur = i - 1;
    for (int j = 1; j <= n; j++) {
      if (a[j] > a[i]) cur++;
    }
    ans = min(ans, cur);
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