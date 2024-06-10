#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l, r; cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x <= l) {
      cout << l << ' ';
    }
    else if (x >= r) {
      cout << r << ' ';
    }
    else {
      cout << x << ' ';
    }
  }
  cout << '\n';

  return 0;
}