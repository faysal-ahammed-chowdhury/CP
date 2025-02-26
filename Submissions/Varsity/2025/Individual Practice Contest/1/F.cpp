#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int sum = 0, mn = 0;
  int ans = a[1];
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    ans = max(ans, sum + (sum - mn - a[i]));
    mn = min(mn, sum);
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