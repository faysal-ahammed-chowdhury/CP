#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int ans = 0;
  int sum1 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 += a[i];
    int sum2 = 0;
    for (int j = i; j <= n; j++) {
      sum2 += b[j];
    }
    ans = max(ans, sum1 + sum2);
  }
  cout << ans << '\n';

  return 0;
}