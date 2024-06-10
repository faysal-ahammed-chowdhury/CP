#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int cnt = 0, x, y;
  do {
    cnt++;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= a[i] == c[i];
    }
    if (ok) {
      x = cnt;
    }
    ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= b[i] == c[i];
    }
    if (ok) {
      y = cnt;
    }
  } while (next_permutation(c + 1, c + n + 1));

  cout << abs(x - y) << '\n';

  return 0;
}