#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) break;
    a[i]--;
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      ans += a[i] - a[i - 1];
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}