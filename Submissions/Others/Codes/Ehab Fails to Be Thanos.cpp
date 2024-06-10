#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x = n + n;
  int a[x + 1];
  for (int i = 1; i <= x; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + x + 1);
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 += a[i];
  }
  for (int i = n + 1; i <= x; i++) {
    sum2 += a[i];
  }

  if (sum1 == sum2) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i <= x; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}