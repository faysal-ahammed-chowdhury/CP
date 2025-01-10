#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i =1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    int mn = a[i];
    for (int j = i; j <= i + k - 1; j++) {
      mn = min(mn, a[j]);
    }
    // cout << mn << ' ';
    ans += mn;
  }

  cout << ans << '\n';

  return 0;
}