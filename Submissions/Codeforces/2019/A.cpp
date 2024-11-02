#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int mx1 = 0, mx2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i & 1) mx1 = max(mx1, a[i]);
    else mx2 = max(mx2, a[i]);
  }
  int odd_cnt = (n / 2) + (n % 2);
  int even_cnt = (n / 2);
  int ans1 = mx1 + odd_cnt;
  int ans2 = mx2 + even_cnt;
  cout << max(ans1, ans2) << '\n';
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