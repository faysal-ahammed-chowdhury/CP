#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  if (n % 2 == 0) {
    int ans = 0;
    for (int i = 2; i <= n; i += 2) {
      ans = max(ans, abs(a[i] - a[i - 1]));
    }
    cout << ans << '\n';
  }
  else {
    int ans = 1e18;
    for (int i = 1; i <= n; i += 2) {
      int mx = 0;
      for (int j = 2; j < i; j += 2) {
        mx = max(mx, abs(a[j] - a[j - 1]));
      }
      for (int j = i + 2; j <= n; j += 2) {
        mx = max(mx, abs(a[j] - a[j - 1]));
      }
      ans = min(ans, mx);
    }
    cout << ans << '\n';
  }
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