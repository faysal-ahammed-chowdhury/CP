#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 1e18, sum = 0;
  int mn = 1e9;
  for (int i = 1; i <= n; i++) {
    if (i + 1 <= n) {
      int tmp = min(mn, a[i] + a[i + 1]);
      ans = min(ans, sum + tmp);
    }
    mn = min(mn, a[i]);
    sum += mn;
  }
  ans = min(ans, sum);
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