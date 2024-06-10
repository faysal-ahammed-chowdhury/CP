#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }

  do {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int x = a[(i + 2) % n];
      int y = (a[i] + x) % k;
      if (y != 0) {
        cout << i << '\n';
        ok = false;
        break;
      }
    }

    if (ok) {
      for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
      }
      cout << '\n';
    }
    break;
  } while (next_permutation(a, a + n));

  return 0;
}