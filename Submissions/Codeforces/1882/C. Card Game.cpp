#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0, add = 0;
  for(int i = n; i > 0; i--) {
    int x = (i & 1) ? a[i] : 0;
    ans = max(ans, add + x);
    add += max(0, a[i]);
  }
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