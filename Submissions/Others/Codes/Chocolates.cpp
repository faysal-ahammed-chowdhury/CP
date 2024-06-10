#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int now = 2e9;
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    if (now <= 1) break;
    int x = min(a[i], now - 1);
    ans += x;
    now = x;
  }

  cout << ans << '\n';

  return 0;
}