#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  array<int, 2> b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i][0];
    b[i][1] = i;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    ans[b[i][1]] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}