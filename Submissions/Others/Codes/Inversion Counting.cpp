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
  long long inv_cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) inv_cnt++;
    }
  }
  inv_cnt %= 2;
  int m; cin >> m;
  while (m--) {
    int l, r; cin >> l >> r;
    int d = r - l + 1;
    inv_cnt += ((d * (d - 1)) / 2);
    inv_cnt %= 2;
    if (inv_cnt) cout << "odd\n";
    else cout << "even\n";
  }

  return 0;
}