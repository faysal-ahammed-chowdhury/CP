#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  reverse(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  long long ans = a[n];
  for (int i = 1; i < n; i++) {
    if (a[i] > 0) ans += a[i];
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